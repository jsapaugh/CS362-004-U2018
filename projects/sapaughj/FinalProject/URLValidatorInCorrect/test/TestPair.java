/*********************************************
 * Authors : Jacob Sapaugh, Noah Beach, Michele Larson
 * Class : CS 362 Intro To Software Engineering II
 * School : Oregon State University
 * Date : 08/05/2018
 **********************************************/
public class TestPair 
{
    public String urlToTest;
    public boolean validity;
    
    public TestPair(String urlToTest, boolean isValid) 
    {
        super();
        this.urlToTest = urlToTest;
        this.validity = isValid;
    }

    public String getUrlToTest() 
    {
        return urlToTest;
    }
    
    public void setUrlToTest(String urlToTest) 
    {
        this.urlToTest = urlToTest;
    }
    
    public boolean getValidity() 
    {
        return validity;
    }
    
    public void setValidity(boolean isValid) 
    {
        this.validity = isValid;
    }
}
