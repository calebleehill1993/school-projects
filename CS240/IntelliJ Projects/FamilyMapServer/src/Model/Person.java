package Model;

/** Object that holds all the parameters for a Person */
public class Person {

    //Class properties
    /** uniquely identifies each Person object */
    String personID;
    /** userName from User Class (Which User is the Person connected to) */
    String descendant;
    String firstName;
    String lastName;
    /** "m" or "f" */
    String gender;
    /** personID of "father" Person object */
    String fatherID;
    /** personID of "mother" Person object */
    String motherID;
    /** personID of "spouse" Person object */
    String spouseID;

    /** Creates a Person using only the descendant. This will generate all the other information
     *
     * @param descendant */
    public Person(String descendant) {

    }

    /** Creates a person for the user
     *
     * @param user */
    public Person(User user) {

    }

    /** Generates a personID and sets it for the person. */
    public void generatePersonID() {

    }

    /** Generates a firstName and sets it for the person. */
    public void generateFirstName() {

    }

    /** Generates a lastName and sets it for the person. */
    public void generateLastName() {

    }

    /** Generates a gender and sets it for the person. */
    public void generateGender() {

    }

}
