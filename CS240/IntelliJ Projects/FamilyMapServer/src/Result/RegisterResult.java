package Result;

import Model.AuthToken;
import Request.RegisterRequest;

/** Shows result of RegisterService, returns an authToken (which has username) and personID or error message */
public class RegisterResult {

    String errorMessage;
    AuthToken authToken;

    /** builds RegisterResult with errorMessage
     *
     * @param errorMessage
     */
    public RegisterResult(String errorMessage) {

    }

    /** builds RegisterResult with authToken
     *
     * @param authToken
     */
    public RegisterResult(AuthToken authToken) {

    }
}
