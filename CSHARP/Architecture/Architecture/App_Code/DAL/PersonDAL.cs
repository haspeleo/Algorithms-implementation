using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Data.SqlClient;


/// <summary>
/// Summary description for PersonDAL
/// </summary>
public class PersonDAL 
{
    string connStr = ConfigurationManager.ConnectionStrings["TutTestConn"].ToString();

	public PersonDAL()
	{

	}

    /// <summary>
    /// Used to insert records into database
    /// </summary>
    /// <param name="p"></param>
    /// <returns></returns>
    public int Insert(Person person)
    {
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        SqlCommand dCmd = new SqlCommand("InsertData", conn);
        dCmd.CommandType = CommandType.StoredProcedure;
        try
        {
            dCmd.Parameters.AddWithValue("@firstName", person.FirstName);
            dCmd.Parameters.AddWithValue("@lastName", person.LastName);
            dCmd.Parameters.AddWithValue("@age", person.Age);
            return dCmd.ExecuteNonQuery();
        }
        catch
        {
            throw;
        }
        finally
        {
            dCmd.Dispose();
            conn.Close();
            conn.Dispose();
        }
    }


    /// <summary>
    /// Update record into database
    /// </summary>
    /// <param name="p"></param>
    /// <returns></returns>
    public int Update(Person person)
    {
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        SqlCommand dCmd = new SqlCommand("UpdateData", conn);
        dCmd.CommandType = CommandType.StoredProcedure;
        try
        {
            dCmd.Parameters.AddWithValue("@firstName", person.FirstName);
            dCmd.Parameters.AddWithValue("@lastName", person.LastName);
            dCmd.Parameters.AddWithValue("@age", person.Age);
            dCmd.Parameters.AddWithValue("@personID", person.PersonID);
            return dCmd.ExecuteNonQuery();
        }
        catch
        {
            throw;
        }
        finally
        {
            dCmd.Dispose();
            conn.Close();
            conn.Dispose();
        }
    }

    /// <summary>
    /// Load all records from database
    /// </summary>
    /// <returns></returns>
    public DataTable Load()
    {
        SqlConnection conn = new SqlConnection(connStr);
        SqlDataAdapter dAd = new SqlDataAdapter("LoadAll", conn);
        dAd.SelectCommand.CommandType = CommandType.StoredProcedure;
        DataSet dSet = new DataSet();
        try
        {
            dAd.Fill(dSet, "PersonTable");
            return dSet.Tables["PersonTable"];
        }
        catch
        {
            throw;
        }
        finally
        {
            dSet.Dispose();
            dAd.Dispose();
            conn.Close();
            conn.Dispose();
        }
    }

    /// <summary>
    /// Delete record from database
    /// </summary>
    /// <param name="person"></param>
    /// <returns></returns>
    public int Delete(Person person)
    {
        SqlConnection conn = new SqlConnection(connStr);
        conn.Open();
        SqlCommand dCmd = new SqlCommand("DeleteData", conn);
        dCmd.CommandType = CommandType.StoredProcedure;
        try
        {
            dCmd.Parameters.AddWithValue("@personID", person.PersonID);
            return dCmd.ExecuteNonQuery();
        }
        catch
        {
            throw;
        }
        finally
        {
            dCmd.Dispose();
            conn.Close();
            conn.Dispose();
        }
    }

}
