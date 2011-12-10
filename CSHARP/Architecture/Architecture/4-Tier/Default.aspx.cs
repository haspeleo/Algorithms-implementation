using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

public partial class _4_Tier_Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    /// <summary>
    /// Add records into database
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    protected void AddRecords(object sender, EventArgs e)
    {
        //Lets validate the page first
        if (!Page.IsValid)
            return;

        int intResult = 0;
        // Page is valid, lets go ahead and insert records
        // Instantiate BAL object
        PersonBAL pBAL = new PersonBAL();
        // Instantiate the object we have to deal with
        Person person = new Person();
        // set the properties of the object
        person.FirstName = txtFirstName.Text;
        person.LastName = txtLastName.Text;
        person.Age = Int32.Parse(txtAge.Text);

        try
        {
            intResult = pBAL.Insert(person);
            if (intResult > 0)
                lblMessage.Text = "New record inserted successfully.";
            else
                lblMessage.Text = "FirstName [<b>"+ txtFirstName.Text +"</b>] alredy exists, try another name";

        }
        catch (Exception ee)
        {
            lblMessage.Text = ee.Message.ToString();
        }
        finally
        {
            person = null;
            pBAL = null;
        }        
    }

}
