package DataAccess;


import Model.Person;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/** Allows access to the Person Table of the database to get and pass in persons */
public class PersonDao {

    private Connection conn;

    public PersonDao(Connection conn) {
        this.conn = conn;
    }

    /** clears the entire Event Table in the database */
    public void clear() throws DataAccessException {
        Database database = new Database();
        database.clearTable("Person");
    }

    /** Adds an event to the database
     *
     * @param person*/
    public boolean add(Person person) throws DataAccessException {
        boolean commit = true;
        String sql = "INSERT INTO Person (personID, descendant, firstName, lastName, " +
                "gender, father, mother, spouse) VALUES(?, ?, ?, ?, ?, ?, ?, ?)";
        try (PreparedStatement stmt = conn.prepareStatement(sql)){
            stmt.setString(1, person.getPersonID());
            stmt.setString(2, person.getDescendant());
            stmt.setString(3, person.getFirstName());
            stmt.setString(4, person.getLastName());
            stmt.setString(5, person.getGender());
            stmt.setString(6, person.getFatherID());
            stmt.setString(7, person.getMotherID());
            stmt.setString(8, person.getSpouseID());

            stmt.executeUpdate();
        } catch (SQLException e) {
            commit = false;
            throw new DataAccessException("Error encountered while inserting into the database");
        }

        return commit;
    }

    /** Deletes an event for the database
     *
     * @param person*/
    public void delete(Person person) {

    }

    /** Finds an person in the database
     *
     * @param personID*/
    public Person find(String personID) throws DataAccessException {
        Person person = null;
        ResultSet rs = null;
        String sql = "SELECT * FROM Person WHERE personID = ?;";
        try (PreparedStatement stmt = conn.prepareStatement(sql)) {
            stmt.setString(1, personID);
            rs = stmt.executeQuery();
            if (rs.next() == true) {
                person = new Person(rs.getString("personID"), rs.getString("descendant"),
                        rs.getString("firstName"), rs.getString("lastName"), rs.getString("gender"),
                        rs.getString("father"), rs.getString("mother"), rs.getString("spouse"));
                return person;
            }
        } catch (SQLException e) {
            e.printStackTrace();
            throw new DataAccessException("Error encountered while finding event");
        } finally {
            if(rs != null) {
                try {
                    rs.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }

        }
        return null;
    }
}
