<form id="form1" runat="server">

    <div>

        <p><a href="List.aspx">List Records</a></p>

        <asp:Label ID="lblMessage" runat="Server" ForeColor="red" 



EnableViewState="False"></asp:Label>

        <table style="border:2px solid #cccccc;">

            <tr style="background-color:#ECF3AB;">

                <th colspan="3">Add Records</th>

            </tr>

            <tr>

                <td>

                    First Name:

                </td>

                <td>

                    <asp:TextBox ID="txtFirstName" runat="Server"></asp:TextBox>

                </td>

                <td>

                    <asp:RequiredFieldValidator ID="req1" runat="Server" Text="*" 



ControlToValidate="txtFirstName" Display="dynamic"></asp:RequiredFieldValidator>

                </td>

            </tr>

            <tr>

                <td>

                    Last Name:

                </td>

                <td>

                    <asp:TextBox ID="txtLastName" runat="Server"></asp:TextBox>

                </td>

                <td>

                    <asp:RequiredFieldValidator ID="req2" runat="Server" Text="*" 



ControlToValidate="txtLastName" Display="dynamic"></asp:RequiredFieldValidator>

                </td>

            </tr>

            <tr>

                <td>

                    Age:

                </td>

                <td>

                    <asp:TextBox ID="txtAge" runat="Server" Columns="4"></asp:TextBox>

                </td>

                <td>

                    <asp:RequiredFieldValidator ID="req3" runat="Server" Text="*" ControlToValidate="txtAge" 



Display="dynamic"></asp:RequiredFieldValidator>

                    <asp:CompareValidator ID="Comp1" runat="Server" Text="Only integer" 



ControlToValidate="txtAge" Operator="DataTypeCheck" Type="Integer"></asp:CompareValidator>

                </td>

            </tr>

            <tr>

                <td> </td>

                <td>

                    <asp:Button ID="btnSubmit" runat="server" Text="Submit" OnClick="AddRecords" />

                </td>

            </tr>

        </table>

    </div>

    </form>

