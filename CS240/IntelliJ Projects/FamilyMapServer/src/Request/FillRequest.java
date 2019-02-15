package Request;

import Result.FillResult;

/** The request that is sent to the FillRequest to populate the server's database. */
public class FillRequest {

    String username;
    int generations;

    /** Builds the FillRequest with just a username and defaults generations to 4
     *
     * @param username*/
    public FillRequest (String username) {

    }

    /** Builds the FillRequest with both username and generations
     *
     * @param username
     * @param generations*/
    public FillRequest (String username, int generations) {

    }
}
