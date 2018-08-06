/*********************************************
 * Authors : Jacob Sapaugh, Noah Beach, Michele Larson
 * Class : CS 362 Intro To Software Engineering II
 * School : Oregon State University
 * Date : 08/05/2018
 **********************************************/

import java.util.ArrayList;
import java.util.List;

import org.junit.Rule;
import org.junit.Test;
import static org.junit.Assert.*;
import org.junit.rules.ErrorCollector;

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
       TestPairList.add(new TestPair("https:/www.google.com", true));
       TestPairList.add(new TestPair("ftp://google.com", true));
       TestPairList.add(new TestPair("http:/www.google.com", false));
       TestPairList.add(new TestPair("does.this._Work?:maybe", false));
       TestPairList.add(new TestPair("jacob://testing.com", false));
       TestPairList.add(new TestPair("https:/fail.com", false));
       TestPairList.add(new TestPair("htp://", false));
       TestPairList.add(new TestPair("testing.com", true));
       TestPairList.add(new TestPair("testing.port.com:@/", false));
       TestPairList.add(new TestPair("http://testing.port.com:100/", true));
       TestPairList.add(new TestPair("http://path.com:8080/@_path/", false));
       TestPairList.add(new TestPair("http://path.com:8090/path", true));
       TestPairList.add(new TestPair("https://path.com:8090/query?this=that", true));
       TestPairList.add(new TestPair("ftp://path.com:100/query?test=space%20here", true));
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

   }
}
