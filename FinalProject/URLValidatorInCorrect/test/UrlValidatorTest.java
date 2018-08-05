/*********************************************
 * Authors : Jacob Sapaugh, Noah Beach, Michele Larson
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
    UrlValidator urlValidator = new UrlValidator();
    
    @Rule
    public ErrorCollector errorCollector = new ErrorCollector();

   @Test
   public void testManualTest()
   {
       String methodName = "testManualTest()";
       System.out.println("Begin test " + methodName);
       //You can use this function to implement your manual testing
       List<ResultPair> resultPairList = new ArrayList<ResultPair>();
       resultPairList.add(new ResultPair("http://google.com", true));
       resultPairList.add(new ResultPair("https:/www.google.com", true));
       resultPairList.add(new ResultPair("ftp://google.com", true));
       resultPairList.add(new ResultPair("http:/www.google.com", false));
       resultPairList.add(new ResultPair("does.this._Work?:maybe", false));
       resultPairList.add(new ResultPair("jacob://testing.com", false));
       resultPairList.add(new ResultPair("https:/fail.com", false));
       resultPairList.add(new ResultPair("htp://", false));
       resultPairList.add(new ResultPair("testing.com", true));
       resultPairList.add(new ResultPair("testing.port.com:@/", false));
       resultPairList.add(new ResultPair("http://testing.port.com:100/", true));
       resultPairList.add(new ResultPair("http://path.com:8080/@_path/", false));
       resultPairList.add(new ResultPair("http://path.com:8090/path", true));
       resultPairList.add(new ResultPair("https://path.com:8090/query?this=that", true));
       resultPairList.add(new ResultPair("ftp://path.com:100/query?test=%20", false));
       boolean actual;
       boolean passed = true;
       for (ResultPair resultPair : resultPairList) 
       {
           actual = urlValidator.isValid(resultPair.item);
           //try catch so if it fails, will continue and can print out all at the end
           try
           {
           assertEquals("Url " + resultPair.item + " tested ",resultPair.valid, actual);
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