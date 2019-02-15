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

    /** Builds 4 generations of people connected to the user */
    public void generateFourGenerations() {

    }

}
