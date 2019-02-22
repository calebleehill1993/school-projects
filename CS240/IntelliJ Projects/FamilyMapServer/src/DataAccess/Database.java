package DataAccess;

import javax.xml.crypto.Data;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * Created by westenm on 2/4/19.
 */

public class Database {
    private Connection conn;

    static {
        try {
            //This is how we set up the driver for our database
            final String driver = "org.sqlite.JDBC";
            Class.forName(driver);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    //Whenever we want to make a change to our database we will have to open a connection and use
    //Statements created by that connection to initiate transactions
    public Connection openConnection() throws DataAccessException {
        try {
            //The Structure for this Connection is driver:language:path
            //The pathing assumes you start in the root of your project unless given a non-relative path
            final String CONNECTION_URL = "jdbc:sqlite:familymap.sqlite";

            // Open a database connection to the file given in the path
            conn = DriverManager.getConnection(CONNECTION_URL);

            // Start a transaction
            conn.setAutoCommit(false);
        } catch (SQLException e) {
            e.printStackTrace();
            throw new DataAccessException("Unable to open connection to database");
        }

        return conn;
    }

    //When we are done manipulating the database it is important to close the connection. This will
    //End the transaction and allow us to either commit our changes to the database or rollback any
    //changes that were made before we encountered a potential error.

    //IMPORTANT: IF YOU FAIL TO CLOSE A CONNECTION AND TRY TO REOPEN THE DATABASE THIS WILL CAUSE THE
    //DATABASE TO LOCK. YOUR CODE MUST ALWAYS INCLUDE A CLOSURE OF THE DATABASE NO MATTER WHAT ERRORS
    //OR PROBLEMS YOU ENCOUNTER
    public void closeConnection(boolean commit) throws DataAccessException {
        try {
            if (commit) {
                //This will commit the changes to the database
                conn.commit();
            } else {
                //If we find out something went wrong, pass a false into closeConnection and this
                //will rollback any changes we made during this connection
                conn.rollback();
            }

            conn.close();
            conn = null;
        } catch (SQLException e) {
            e.printStackTrace();
            throw new DataAccessException("Unable to close database connection");
        }
    }

    public void createTables() throws DataAccessException {

        openConnection();

        try (Statement stmt = conn.createStatement()){
            //First lets open our connection to our database.

            //We pull out a statement from the connection we just established
            //Statements are the basis for our transactions in SQL
            //Format this string to be exaclty like a sql create table command
            String sql = "CREATE TABLE IF NOT EXISTS User (\n" +
                    "    username TEXT PRIMARY KEY NOT NULL UNIQUE,\n" +
                    "    password TEXT NOT NULL,\n" +
                    "    email TEXT NOT NULL,\n" +
                    "    firstName TEXT NOT NULL,\n" +
                    "    lastName TEXT NOT NULL,\n" +
                    "    gender TEXT NOT NULL,\n" +
                    "    personID TEXT  NOT NULL UNIQUE\n" +
                    ");\n" +
                    "\n" +
                    "CREATE TABLE IF NOT EXISTS Person (\n" +
                    "    personID TEXT PRIMARY KEY NOT NULL UNIQUE,\n" +
                    "    descendant TEXT NOT NULL,\n" +
                    "    firstName TEXT NOT NULL,\n" +
                    "    lastName TEXT NOT NULL,\n" +
                    "    gender TEXT NOT NULL,\n" +
                    "    father TEXT,\n" +
                    "    mother TEXT,\n" +
                    "    spouse TEXT\n" +
                    ");\n" +
                    "\n" +
                    "CREATE TABLE IF NOT EXISTS Event (\n" +
                    "    eventID TEXT PRIMARY KEY NOT NULL UNIQUE,\n" +
                    "    descendant TEXT NOT NULL,\n" +
                    "    personID TEXT NOT NULL,\n" +
                    "    latitude TEXT NOT NULL,\n" +
                    "    longitude TEXT NOT NULL,\n" +
                    "    country TEXT NOT NULL,\n" +
                    "    city TEXT NOT NULL,\n" +
                    "    eventType TEXT NOT NULL,\n" +
                    "    year INT NOT NULL\n" +
                    ");\n" +
                    "\n" +
                    "CREATE TABLE IF NOT EXISTS AuthToken (\n" +
                    "    token TEXT PRIMARY KEY NOT NULL UNIQUE,\n" +
                    "    user TEXT NOT NULL\n" +
                    ");";

            stmt.executeUpdate(sql);
            //if we got here without any problems we succesfully created the table and can commit
            closeConnection(true);
        } catch (DataAccessException e) {
            //if our table creation caused an error, we can just not commit the changes that did happen
            closeConnection(false);
            throw e;
        } catch (SQLException e) {
            //if our table creation caused an error, we can just not commit the changes that did happen
            closeConnection(false);
            throw new DataAccessException("SQL Error encountered while creating tables");
        }


    }

    public void clearTable(String table) throws DataAccessException
    {
        openConnection();

        try (Statement stmt = conn.createStatement()){
            String sql = "DELETE FROM " + table;
            stmt.executeUpdate(sql);
            closeConnection(true);
        } catch (DataAccessException e) {
            closeConnection(false);
            throw e;
        } catch (SQLException e) {
            closeConnection(false);
            throw new DataAccessException("SQL Error encountered while clearing tables");
        }
    }

    public void clearTables() throws DataAccessException {
        clearTable("User");
        clearTable("Person");
        clearTable("Event");
        clearTable("AuthToken");
    }

}
