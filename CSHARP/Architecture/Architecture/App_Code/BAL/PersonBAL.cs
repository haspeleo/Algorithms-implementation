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
/// Summary description for PersonBAL
/// </summary>
public class PersonBAL
{
	public PersonBAL()
	{
		
	}

    /// <summary>
    /// insert records into database
    /// </summary>
    /// <param name="person"></param>
    /// <returns></returns>
    public int Insert(Person person)
    {
        PersonDAL pDAL = new PersonDAL();
        try
        {
            return pDAL.Insert(person);
        }
        catch
        {
            throw;
        }
        finally
        {
            pDAL = null;
        }
    }

    /// <summary>
    /// Update records into database
    /// </summary>
    /// <param name="person"></param>
    /// <returns></returns>
    public int Update(Person person)
    {
        PersonDAL pDAL = new PersonDAL();
        try
        {
            return pDAL.Update(person);
        }
        catch
        {
            throw;
        }
        finally
        {
            pDAL = null;
        }
    }

    /// <summary>
    /// Load records from database
    /// </summary>
    /// <returns></returns>
    public DataTable Load()
    {
        PersonDAL pDAL = new PersonDAL();
        try
        {
            return pDAL.Load();
        }
        catch
        {
            throw;
        }
        finally
        {
            pDAL = null;
        }
    }

    /// <summary>
    /// Delete record from database
    /// </summary>
    /// <param name="person"></param>
    /// <returns></returns>
    public int Delete(Person person)
    {
        PersonDAL pDAL = new PersonDAL();
        try
        {
            return pDAL.Delete(person);
        }
        catch
        {
            throw;
        }
        finally
        {
            pDAL = null;
        }
    }

}
