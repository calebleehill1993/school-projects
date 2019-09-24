package Result;

import Model.AuthToken;
import Request.RegisterRequest;

/** Shows result of RegisterService, returns an authToken (which has username) and personID or error message */
public class RegisterResult {

    String result;
    AuthToken authToken;

    /** builds RegisterResult with errorMessage
     *
     * @param result
     */
    public RegisterResult(String result) {

    }

    /** builds RegisterResult with authToken and success string
     *
     * @param authToken
     */
    public RegisterResult(AuthToken authToken) {

    }
}
