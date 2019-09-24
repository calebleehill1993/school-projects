package Model;

/** Object that holds all the parameters for a Person */
public class Person {

    //Class properties
    /** uniquely identifies each Person object */
    private String personID;
    /** userName from User Class (Which User is the Person connected to) */
    private String descendant;
    private String firstName;
    private String lastName;
    /** "m" or "f" */
    private String gender;
    /** personID of "father" Person object */
    private String fatherID;
    /** personID of "mother" Person object */
    private String motherID;
    /** personID of "spouse" Person object */
    private String spouseID;

    /** Creates a Person using only the descendant. This will generate all the other information
     *
     * @param descendant */
    public Person(String descendant) {

    }

    public Person(String personID, String descendant, String firstName, String lastName, String gender, String father, String mother, String spouse) {
        this.personID = personID;
        this.descendant = descendant;
        this.firstName = firstName;
        this.lastName = lastName;
        this.gender = gender;
        this.fatherID = father;
        this.motherID = mother;
        this.spouseID = spouse;
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

    public String getPersonID() {
        return personID;
    }

    public String getDescendant() {
        return descendant;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getGender() {
        return gender;
    }

    public String getFatherID() {
        return fatherID;
    }

    public String getMotherID() {
        return motherID;
    }

    public String getSpouseID() {
        return spouseID;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null)
            return false;
        if (o instanceof Person) {
            Person oPerson = (Person) o;
            if (oPerson.getPersonID().equals(getPersonID()) &&
                    oPerson.getDescendant().equals(getDescendant()) &&
                    oPerson.getFirstName().equals(getFirstName()) &&
                    oPerson.getLastName().equals(getLastName()) &&
                    oPerson.getGender().equals(getGender()) &&
                    oPerson.getFatherID().equals(getFatherID()) &&
                    oPerson.getMotherID().equals((getMotherID())) &&
                    oPerson.getSpouseID().equals(getSpouseID())) {
                return true;
            }
        }
        return false;
    }

}
