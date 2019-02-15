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
}
