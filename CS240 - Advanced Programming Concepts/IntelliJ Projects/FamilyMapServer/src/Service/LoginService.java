package Service;

import Request.LoginRequest;
import Result.LoginResult;

/** Logs the user in if username and password match database. Returns LoginResult with authToken.*/
public class LoginService {

    LoginRequest loginRequest;

    /** Builds the LoginRequest
     *
     * @param loginRequest*/
    public LoginService(LoginRequest loginRequest) {

    }

    /** Logs the user in and returns both response and authToken in LoginResult
     *
     * @return LoginResult*/
    public LoginResult login() {
        return null;
    }

}
