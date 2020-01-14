package Service;

import Request.RegisterRequest;
import Result.RegisterResult;

/** Creates a new user account, generates 4 generations of ancestor data for the new user and logs the user in.
 */
public class RegisterService {

    RegisterResult registerResult;

    /** Builds RegisterService with registerRequest given
     *
     * @param registerRequest
     */
    public RegisterService(RegisterRequest registerRequest) {

    }
    /** If RegisterResult is good, creates a new user account, generates 4 generations of ancestor
     * data for the new user and logs the user in. The RegisterResult has the authToken in it as well.
     * @return  RegisterResult
     */
    public RegisterResult register() {
        return null;
    }

}
