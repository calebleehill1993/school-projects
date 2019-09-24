package Model;

/** Object that holds all the parameters of an Event */
public class Event {

    //Class properties
    String eventID; //Unique ID for this event
    String descendant; //userName from User Class (Which User is the Person connected to)
    String personID; //personID for Person object this event belongs to
    String latitude;
    String longitude;
    String country;
    String city;
    String eventType;
    int year;

    /** Builds the event using the descendant and personID
     *
     * @param descendant
     * @param personID
     */
    public Event(String descendant, String personID) {

    }

    /** Generates random eventID and sets it. */
    public void generateEventID() {

    }

    /** Generates random latitude and sets it. */
    public void generateLatitude() {

    }

    /** Generates random longitude and sets it. */
    public void generateLongitude() {

    }

    /** Generates random country and sets it. */
    public void generateCountry() {

    }

    /** Generates random city and sets it. */
    public void generateCity() {

    }

    /** Generates random eventType and sets it. */
    public void generateEventType() {

    }

    /** Generates random year and sets it. */
    public void generateYear() {

    }
}
