package com.minella.easyMock;
import junit.framework.TestCase;
import static org.easymock.EasyMock.createStrictMock;
import static org.easymock.EasyMock.expect;
import static org.easymock.EasyMock.replay;
import static org.easymock.EasyMock.verify;
import static org.easymock.EasyMock.eq;
/**
* Test case for LoginService.
*/
public class TestLoginService extends TestCase{

     private LoginServiceImpl service;
     private UserDao mockDao;

     /**
     * setUp overrides the default, empty implementation provided by
     * JUnit's TestCase.  We will use it to instantiate our required
     * objects so that we get a clean copy for each test.
     */
     @Override
     public void setUp() {
          service = new LoginServiceImpl();
          mockDao = createStrictMock(UserDao.class);
          service.setUserDAO(mockDao);
     }

     /**
      * This method will test the "rosy" scenario of passing a valid
      * username and password and retrieveing the user.  Once the user
      * is returned to the service, the service will return true to
      * the caller.
      */
      public void testRosyScenario() {
           User results = new User();
           String userName = "testUserName";
           String password = "testPassword";
           String passwordHash = 
                "�Ӷ&I7���Ni=.";
           expect(mockDao.loadByUsernameAndPassword(eq(userName), eq(passwordHash)))
                .andReturn(results);

           replay(mockDao);
           assertTrue(service.login(userName, password));
           verify(mockDao);
      }
}
