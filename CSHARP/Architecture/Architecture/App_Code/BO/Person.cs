using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

/// <summary>
/// Summary description for Person
/// </summary>
public class Person
{
	public Person()
	{
        
	}


    int m_PersonID = 0;
    string m_FirstName = string.Empty;
    string m_LastName = string.Empty;
    int m_Age = 0;

    #region Propertiers
    public int PersonID
    {
        get { return m_PersonID; }
        set { m_PersonID = value; }
    }
    
    public string FirstName
    {
        get { return m_FirstName; }
        set { m_FirstName = value; }
    }
    
    public string LastName
    {
        get { return m_LastName; }
        set { m_LastName = value; }
    }
    
    public int Age
    {
        get { return m_Age; }
        set { m_Age = value; }
    }
    #endregion Properties


}
