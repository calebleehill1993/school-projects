package DataAccess;

import Model.User;

import java.sql.Connection;

import org.junit.*;
import static org.junit.Assert.*;

//We will use this to test that our insert function is working and failing in the right ways
public class UserDaoTest {
    Database db;
    User myUser;

    @Before
    public void setUp() throws Exception {
        //here we can set up any classes or variables we will need for the rest of our tests
        //lets create a new database
        db = new Database();
        //and a new event with random data
        myUser = new User("calebhill", "secret", "calebleehill1993@gmail.com",
                 "Caleb", "Hill",
                "m", "abcd1234");
        //and make sure to initialize our tables since we don't know if our database files exist yet
        db.createTables();
    }

    @After
    public void tearDown() throws Exception {
        //here we can get rid of anything from our tests we don't want to affect the rest of our program
        //lets clear the tables so that any data we entered for testing doesn't linger in our files
        db.clearTable("User");
    }

    @Test
    public void addPass() throws Exception {
        //We want to make sure insert works
        //First lets create an Event that we'll set to null. We'll use this to make sure what we put
        //in the database is actually there.
        User compareTest = null;
        //Let's clear the database as well so any lingering data doesn't affect our tests
        db.clearTable("User");
        try {
            //Let's get our connection and make a new DAO
            Connection conn = db.openConnection();
            UserDao uDao = new UserDao(conn);
            //While insert returns a bool we can't use that to verify that our function actually worked
            //only that it ran without causing an error
            uDao.add(myUser);
            //So lets use a find function to get the event that we just put in back out
            compareTest = uDao.find(myUser.getUserName());
            db.closeConnection(true);
        } catch (DataAccessException e) {
            db.closeConnection(false);
        }
        //First lets see if our find found anything at all. If it did then we know that if nothing
        //else something was put into our database, since we cleared it in the beginning
        assertNotNull(compareTest);
        //Now lets make sure that what we put in is exactly the same as what we got out. If this
        //passes then we know that our insert did put something in, and that it didn't change the
        //data in any way
        assertEquals(myUser, compareTest);

    }

    @Test
    public void addFail() throws Exception {
        //lets do this test again but this time lets try to make it fail
        boolean didItWork = true;
        try {
            Connection conn = db.openConnection();
            UserDao uDao = new UserDao(conn);
            //if we call the function the first time it will insert it successfully
            uDao.add(myUser);
            //but our sql table is set up so that "username" must be unique. So trying to insert it
            //again will cause the function to throw an exception
            uDao.add(myUser);
            db.closeConnection(didItWork);
        } catch (DataAccessException e) {
            //If we catch an exception we will end up in here, where we can change our boolean to
            //false to show that our function failed to perform correctly
            db.closeConnection(false);
            didItWork = false;
        }
        //Check to make sure that we did in fact enter our catch statement
        assertFalse(didItWork);
        //Since we know our database encountered an error, both instances of insert should have been
        //rolled back. So for added security lets make one more quick check using our find function
        //to make sure that our event is not in the database
        //Set our compareTest to an actual event
        User compareTest = myUser;
        try {
            Connection conn = db.openConnection();
            UserDao uDao = new UserDao(conn);
            //and then get something back from our find. If the event is not in the database we
            //should have just changed our compareTest to a null object
            compareTest = uDao.find(myUser.getPersonID());
            db.closeConnection(true);
        } catch (DataAccessException e) {
            db.closeConnection(false);
        }
        //Now make sure that compareTest is indeed null
        assertNull(compareTest);
    }

    @Test
    public void findPass() throws Exception {
        User compareTest = null;
        db.clearTable("User");
        try {
            Connection conn = db.openConnection();
            UserDao uDao = new UserDao(conn);
            uDao.add(myUser);
            compareTest = uDao.find(myUser.getUserName());
            db.closeConnection(true);
        } catch (DataAccessException e) {
            db.closeConnection(false);
        }
        assertNotNull(compareTest);
        assertEquals(myUser, compareTest);
    }


    @Test
    public void findFail() throws Exception {
        boolean didItWork = true;
        User compareTest = null;
        try {
            Connection conn = db.openConnection();
            UserDao uDao = new UserDao(conn);
            uDao.add(myUser);
            compareTest = uDao.find("wrongName");
            db.closeConnection(didItWork);
        } catch (DataAccessException e) {
            db.closeConnection(false);
            didItWork = false;
        }
        assertNull(compareTest);
    }

    @Test
    public void clearPass() throws Exception {
        db.clearTable("User");
        User compareTest = null;
        try {
            Connection conn = db.openConnection();
            UserDao uDao = new UserDao(conn);
            uDao.add(myUser);
            uDao.clear();
            compareTest = uDao.find(myUser.getUserName());
        }
        catch (DataAccessException e) {
            db.closeConnection(false);
        }
        assertNull(compareTest);
    }

}

