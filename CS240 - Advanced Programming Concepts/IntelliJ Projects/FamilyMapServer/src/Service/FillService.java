package Service;

import Request.FillRequest;
import Result.FillResult;

/** Populates the server's database with generated data for the specified user name.
 The required "username" parameter must be a user already registered with the server. If there is
 any data in the database already associated with the given user name, it is deleted. The
 optional “generations” parameter lets the caller specify the number of generations of ancestors
 to be generated, and must be a non-neg */
public class FillService {

    FillRequest fillRequest;

    /** Builds the FillService by grabbing fillRequest.
     *
     * @param fillRequest
     */
    public FillService(FillRequest fillRequest) {

    }

    /** Takes the request and fills the table with people it has generated for the
     * username in fillRequest. If username already has data that's associated with it,
     * then we clear the table and then fill it with generated data.
     *
     * @return FillResult that has display message for error or success.
     */
    public FillResult fill() {
        return null;
    }
}
