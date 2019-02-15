package Model;

/** User class description */
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

    /** Constructor Description of User() */
    public User() {
        // Do something ...
    }

    /** gets email
     * @return      gets the email String
     */
    public String getEmail() {
        return email;
    }
}
