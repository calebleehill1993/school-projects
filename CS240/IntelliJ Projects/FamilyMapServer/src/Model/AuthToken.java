package Model;

/** Puts a username and authToken in the same object */
public class AuthToken {

    //Class properties
    /** Unique to each login (different for same user at different clients) */
    String authToken;
    /** userName from User Class */
    String user;

    /** Builds an AuthToken with username and sets AuthToken with generator
     *
     * @param username*/
    public AuthToken (String username){

    }

    /** Generates a random authToken and sets it for the AuthToken */
    public void generateAuthToken() {

    }
}