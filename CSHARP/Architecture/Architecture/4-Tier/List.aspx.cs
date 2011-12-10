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
using System.Collections.Generic;

public partial class _4_Tier_List : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
            BindGrid();
    }


    /// <summary>
    /// Fired when Cancel button is clicked
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    protected void CancelRecord(object sender, GridViewCancelEditEventArgs e)
    {
        GridView1.EditIndex = -1;
        BindGrid();
    }


    /// <summary>
    /// Fires when Edit button is clicked
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    protected void EditRecord(object sender, GridViewEditEventArgs e)
    {
        GridView1.EditIndex = e.NewEditIndex;
        BindGrid();
    }

    /// <summary>
    /// Fires when Update button is clicked
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    protected void UpdateRecord(object sender, GridViewUpdateEventArgs e)
    {
        int personID = Int32.Parse(GridView1.DataKeys[e.RowIndex].Value.ToString());
        int intResult = 0;
        GridViewRow row = GridView1.Rows[e.RowIndex];

        TextBox tFN = (TextBox) row.FindControl("txtFName");
        TextBox tLN = (TextBox)row.FindControl("txtLName");
        TextBox tAge = (TextBox)row.FindControl("txtAge");

        // instantiate BAL
        PersonBAL pBAL = new PersonBAL();
        Person person = new Person();
        try
        {
            person.PersonID = personID;
            person.FirstName = tFN.Text;
            person.LastName = tLN.Text;
            person.Age = Int32.Parse(tAge.Text);
            intResult = pBAL.Update(person);
            if (intResult > 0)
                lblMessage.Text = "Record Updated Successfully.";
            else
                lblMessage.Text = "Record couldn't updated";
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

        GridView1.EditIndex = -1;
        // Refresh the list
        BindGrid();
    }

    /// <summary>
    /// fires when Delete button is clicked
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    protected void DeleteRecord(object sender, GridViewDeleteEventArgs e)
    {
        int personID = Int32.Parse(GridView1.DataKeys[e.RowIndex].Value.ToString()); 
        

        // instantiate BAL
        PersonBAL pBAL = new PersonBAL();
        Person person = new Person();
        try
        {
            person.PersonID = personID;
            pBAL.Delete(person);

            lblMessage.Text = "Record Deleted Successfully.";
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

        GridView1.EditIndex = -1;
        // Refresh the list
        BindGrid();
    }

    /// <summary>
    /// Fires when page links are clicked
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    protected void ChangePage(object sender, GridViewPageEventArgs e)
    {
        GridView1.PageIndex = e.NewPageIndex;
        // Refresh the list
        BindGrid();
    }

    /// <summary>
    /// Fires when Columns heading are clicked
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    protected void SortRecords(object sender, GridViewSortEventArgs e)
    {
        DataTable dataTable = GridDataSource();

        if (dataTable != null)
        {
            DataView dataView = new DataView(dataTable);

            dataView.Sort = GetSortExpression(e);

            GridView1.DataSource = dataView;
            GridView1.DataBind();
        }
    }

    #region Private Methods

    /// <summary>
    /// Bind the gridview
    /// </summary>
    private void BindGrid()
    {
        GridView1.DataSource = GridDataSource();
        GridView1.DataBind();
    }

    /// <summary>
    /// Get GridView DataSource
    /// </summary>
    private DataTable GridDataSource()
    {
        PersonBAL p = new PersonBAL();
        DataTable dTable = new DataTable();
        try
        {
            dTable = p.Load();
        }
        catch (Exception ee)
        {
            lblMessage.Text = ee.Message.ToString();
        }
        finally
        {
            p = null;
        }

        return dTable;
    }

    /// <summary>
    /// Get sort expression for the gridview
    /// </summary>
    /// <param name="e"></param>
    /// <returns></returns>
    private string GetSortExpression(GridViewSortEventArgs e)
    {
        string sortDirection = string.Empty;
         // if clicked on the same column twice then let it toggle the sort order, else reset to ascending
        if (ViewState["SortExpression"] != null)
        {
            if (!ViewState["SortExpression"].ToString().Equals(e.SortExpression.ToLower()))
            {
                ViewState["SortDirection"] = null;
            }
        }

        if (ViewState["SortDirection"] != null)
        {
            if (ViewState["SortDirection"].ToString().Equals("ASC"))
            {
                sortDirection = "DESC";
                ViewState["SortDirection"] = "DESC";
            }
            else
            {
                sortDirection = "ASC";
                ViewState["SortDirection"] = "ASC";
            }
        }
        else
        {
            ViewState["SortDirection"] = "ASC";
        }
        ViewState["SortExpression"] = e.SortExpression.ToLower();

        return e.SortExpression + " " + sortDirection;
    }
    #endregion Private Methods
}
