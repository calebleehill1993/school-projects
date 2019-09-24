package Model;

import Request.RegisterRequest;

/** Holds all the parameters for a User */
public class User {

    //Class properties
    private String userName;
    private String password;
    private String email;
    private String firstName;
    private String lastName;
    /** "m" or "f" */
    private String gender;
    /** Connects a user to a Person Class */
    private String personID;

    /** Builds a User with all parameters from the RegisterRequest
     * Also builds a person and sets the personID
     *
     * @param registerRequest
     */
    public User(RegisterRequest registerRequest) {
        // Do something ...
    }

    public User(String userName, String password, String email, String firstName, String lastName, String gender, String personID) {
        this.userName = userName;
        this.password = password;
        this.email = email;
        this.firstName = firstName;
        this.lastName = lastName;
        this.gender = gender;
        this.personID = personID;
    }

    /** Builds 4 generations of people connected to the user */
    public void generateFourGenerations() {

    }

    public String getUserName() {
        return userName;
    }

    public String getPassword() {
        return password;
    }

    public String getEmail() {
        return email;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getGender() {
        return gender;
    }

    public String getPersonID() {
        return personID;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null)
            return false;
        if (o instanceof User) {
            User oUser = (User) o;
            if (oUser.getUserName().equals(getUserName()) &&
                    oUser.getPassword().equals(getPassword()) &&
                    oUser.getEmail().equals(getEmail()) &&
                    oUser.getFirstName().equals(getFirstName()) &&
                    oUser.getLastName().equals(getLastName()) &&
                    oUser.getGender().equals(getGender()) &&
                    oUser.getPersonID().equals(getPersonID())) {
                return true;
            }
        }
        return false;
    }
}
