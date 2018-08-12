package test;

/*********************************************
 * Authors : Jacob Sapaugh, Noah Beach, Michele Larson
 **********************************************/
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

/*********************************************
 * Authors : Jacob Sapaugh, Noah Beach, Michele Larson
 **********************************************/

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import org.junit.Rule;
import org.junit.Test;
import org.junit.rules.ErrorCollector;

import src.UrlValidator;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest
{

    @Rule
    public ErrorCollector errorCollector = new ErrorCollector();

    @Test
    public void testManualTest()
    {
        //default schemas allowed
        UrlValidator urlValidator = new UrlValidator();

        //You can use this function to implement your manual testing
        String methodName = "testManualTest()";
        System.out.println("Begin test " + methodName);
        List<TestPair> TestPairList = new ArrayList<TestPair>();
        TestPairList.add(new TestPair("http://google.com", true));
        TestPairList.add(new TestPair("https:/www.google.com", false));
        TestPairList.add(new TestPair("ftp://google.com", true));
        TestPairList.add(new TestPair("http:/www.google.com", false));
        TestPairList.add(new TestPair("does.this._Work?:maybe", false));
        TestPairList.add(new TestPair("jacob://testing.com", false));
        TestPairList.add(new TestPair("https:/fail.com", false));
        TestPairList.add(new TestPair("htp://", false));
        TestPairList.add(new TestPair("testing.com", false));
        TestPairList.add(new TestPair("testing.port.com:@/", false));
        TestPairList.add(new TestPair("http://testing.port.com:100/", true));
        TestPairList.add(new TestPair("http://path.com:8080/@_path/", true));
        TestPairList.add(new TestPair("http://path.com:8090/path", true));
        TestPairList.add(new TestPair("https://path.com:8090/query?this=that", true));
        TestPairList.add(new TestPair("ftp://path.com:100/query?test=space%20here", true));
        TestPairList.add(new TestPair("https://www.dwheeler.com/essays/debugging-agans.html", true));
        TestPairList.add(new TestPair("google.com", false));
        TestPairList.add(new TestPair("www.google.com", false));
        TestPairList.add(new TestPair("www.google.com:9080", false));
        TestPairList.add(new TestPair("testing.port.com:100/", false));
        TestPairList.add(new TestPair("path.com:8090/path", false));
        TestPairList.add(new TestPair("path.com:8090/query?this=that", false));
        TestPairList.add(new TestPair("path.com:100/query?test=space%20here", false));
        TestPairList.add(new TestPair("dwheeler.com/essays/debugging-agans.html", false));
        boolean actual;
        boolean passed = true;
        for (TestPair TestPair : TestPairList)
        {
            actual = urlValidator.isValid(TestPair.getUrlToTest());
            //try catch so if it fails, will continue and can print out all at the end
            try
            {
                assertEquals("Url " + TestPair.getUrlToTest() + " tested ", TestPair.getValidity(), actual);
            }
            catch (Throwable t)
            {
                errorCollector.addError(t);
                System.err.println(t.getMessage());
                passed = false;
            }
        }
        assertTrue("Overall status is fail for test, check logs for details", passed);
    }

    @Test
    public void testYourFirstPartition()
    {
        //You can use this function to implement your First Partition testing
    }

    @Test
    public void testYourSecondPartition(){
        //You can use this function to implement your Second Partition testing

    }
    //You need to create more test cases for your Partitions if you need to

    @Test
    public void testIsValid()
    {
        //You can use this function for programming based testing
        String methodName = "testIsValid()";
        System.out.println("Begin test " + methodName);

        //default schemas allowed
        UrlValidator urlValidator = new UrlValidator();

        boolean passed = true;
        Random rand = new Random(); // Use random testing to create URLs to test

        for (int i = 0; i < 100; i++) {
            boolean actual = false;
            boolean partsValid = false;

            StringBuilder testURL = new StringBuilder();

            // Generate random URL parts
            TestPair randScheme = testUrlScheme[rand.nextInt(testUrlScheme.length)];
            TestPair randAuth = testUrlAuthority[rand.nextInt(testUrlAuthority.length)];
            TestPair randPort = testUrlPort[rand.nextInt(testUrlPort.length)];
            TestPair randPath = testUrlPath[rand.nextInt(testUrlPath.length)];
            TestPair randQuery = testUrlQuery[rand.nextInt(testUrlQuery.length)];

            // Check each part for validity
            if (randScheme.validity && randAuth.validity && randPort.validity && randPath.validity && randQuery.validity) {
                partsValid = true;
            }

            // Create test url string
            testURL.append(randScheme.urlToTest);
            testURL.append(randAuth.urlToTest);
            testURL.append(randPort.urlToTest);
            testURL.append(randPath.urlToTest);
            testURL.append(randQuery.urlToTest);

            actual = urlValidator.isValid(testURL.toString());

            try
            {
//                System.out.println("Testing: " + testURL.toString() + "| partsValid: " + partsValid + " | actual: " + actual);
                assertEquals("Assert: Url " + testURL.toString() + " tested ", partsValid, actual);
            }
            catch (Throwable t)
            {
                errorCollector.addError(t);
                System.err.println(t.getMessage());
                passed = false;
            }

        }

        assertTrue("Overall status is fail for test, check logs for details", passed);
    }

    TestPair[] testUrlScheme =
            {
                    new TestPair("http://", true),
                    new TestPair("ftp://", true),
                    new TestPair("h3t://", true),
                    new TestPair("3ht://", false),
                    new TestPair("http:/", false),
                    new TestPair("http:", false),
                    new TestPair("http/", false),
                    new TestPair("://", false),
                    new TestPair("", true)
            };

    TestPair[] testUrlAuthority =
            {
                    new TestPair("www.google.com", true),
                    new TestPair("go.com", true),
                    new TestPair("go.au", true),
                    new TestPair("0.0.0.0", true),
                    new TestPair("255.255.255.255", true),
                    new TestPair("256.256.256.256", false),
                    new TestPair("255.com", true),
                    new TestPair("1.2.3.4.5", false),
                    new TestPair("1.2.3.4.", false),
                    new TestPair("1.2.3", false),
                    new TestPair(".1.2.3.4", false),
                    new TestPair("go.a", false),
                    new TestPair("go.a1a", false),
                    new TestPair("go.1aa", false),
                    new TestPair("aaa.", false),
                    new TestPair(".aaa", false),
                    new TestPair("aaa", false),
                    new TestPair("", false)
            };
    TestPair[] testUrlPort =
            {
                    new TestPair(":80", true),
                    new TestPair(":65535", true),
                    new TestPair(":0", true),
                    new TestPair("", true),
                    new TestPair(":-1", false),
                    new TestPair(":65636",false),
                    new TestPair(":65a", false)
            };
    TestPair[] testUrlPath =
            {
                    new TestPair("/test1", true),
                    new TestPair("/t123", true),
                    new TestPair("/$23", true),
                    new TestPair("/..", false),
                    new TestPair("/../", false),
                    new TestPair("/test1/", true),
                    new TestPair("", true),
                    new TestPair("/test1/file", true),
                    new TestPair("/..//file", false),
                    new TestPair("/test1//file", false)
            };
    //Test allow2slash, noFragment
    TestPair[] testUrlPathOptions =
            {
                    new TestPair("/test1", true),
                    new TestPair("/t123", true),
                    new TestPair("/$23", true),
                    new TestPair("/..", false),
                    new TestPair("/../", false),
                    new TestPair("/test1/", true),
                    new TestPair("/#", false),
                    new TestPair("", true),
                    new TestPair("/test1/file", true),
                    new TestPair("/t123/file", true),
                    new TestPair("/$23/file", true),
                    new TestPair("/../file", false),
                    new TestPair("/..//file", false),
                    new TestPair("/test1//file", true),
                    new TestPair("/#/file", false)
            };

    TestPair[] testUrlQuery =
            {
                    new TestPair("?action=view", true),
                    new TestPair("?action=edit&mode=up", true),
                    new TestPair("", true)
            };

    Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPath, testUrlQuery};
    Object[] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
    int[] testPartsIndex = {0, 0, 0, 0, 0};

}