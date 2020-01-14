package Result;

import Model.AuthToken;

/** Shows result of LoginService and returns with an authToken */
public class LoginResult {

    String result;
    AuthToken authToken;

    /** Builds LoginResult with the result without the authToken (so a failure)
     *
     * @param result*/
    public LoginResult(String result) {

    }

    /** Builds the LoginResult with the authToken and sets the result as success */
    public LoginResult(AuthToken authToken) {

    }
}
