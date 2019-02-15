package Service;

import Model.Event;
import Model.Person;
import Model.User;
import Request.LoadRequest;
import Result.LoadResult;

import java.util.ArrayList;

public class LoadService {

    ArrayList<User> users;
    ArrayList<Person> persons;
    ArrayList<Event> events;

    /** puts the loadRequest string into arraylists if syntax is correct
     *
     * @param loadRequest*/
    public LoadService(LoadRequest loadRequest) {

    }

    /** splits the loadRequest into pieces and stores them in the proper arraylists. */
    public void parseLoadRequest(LoadRequest loadRequest) {

    }

    /** Loads the objects from the arraylists into the database if successful
     *
     * @return LoadResult*/
    public LoadResult load() {
        return null;
    }
}
