package Service;

import Request.ClearRequest;
import Result.ClearResult;

/** Deletes All data from the database,  including user accounts, auth tokens, and generated person and event data.
 * It returns with ClearResult which carries the text to display.
 * */
public class ClearService {

    ClearRequest clearRequest;

    /** Takes the ClearRequest and saves as clearRequest
     * @param   clearRequest saves as clearRequest */
    public ClearService (ClearRequest clearRequest) {

    }

    /** Calls on the DAO's to clear the database. Only happens if request is good.
     * @return  ClearResult that contains a String with message. */
    public ClearResult clear() {
        return null;
    }

}
