<form id="form1" runat="server">

    <div>

        <p><a href="Default.aspx">Add Record</a></p>

        <asp:Label ID="lblMessage" runat="Server" ForeColor="red" EnableViewState="False"></asp:Label>

        <asp:GridView ID="GridView1" runat="server" CellPadding="4" ForeColor="#333333" GridLines="None"

         DataKeyNames="PersonID" AutoGenerateEditButton="True" AutoGenerateColumns="False"

          OnRowEditing="EditRecord" OnRowUpdating="UpdateRecord" OnRowCancelingEdit="CancelRecord"

           OnRowDeleting="DeleteRecord" AllowPaging="True" AllowSorting="true" PageSize="5" 

           OnPageIndexChanging="ChangePage" OnSorting="SortRecords">

            <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />

            <RowStyle BackColor="#EFF3FB" />

            <EditRowStyle BackColor="#2ff1BF" />

            <SelectedRowStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />

            <PagerStyle BackColor="#2461BF" ForeColor="White" HorizontalAlign="Center" />

            <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />

            <AlternatingRowStyle BackColor="White" />

            <Columns>

                <asp:BoundField DataField="PersonID" HeaderText="Person ID" ReadOnly="True"  SortExpression="PersonID" />

                <asp:TemplateField HeaderText="First Name" SortExpression="FirstName">

                    <ItemTemplate>

                        <%# Eval("FirstName") %>

                    </ItemTemplate>

                    <EditItemTemplate>

                        <asp:TextBox ID="txtFName" runat="Server" Text='<%# Eval("FirstName") %>'></asp:TextBox>

                    </EditItemTemplate>

                </asp:TemplateField>

                <asp:TemplateField HeaderText="Last Name" SortExpression="LastName">

                    <ItemTemplate>

                        <%# Eval("LastName") %>

                    </ItemTemplate>

                    <EditItemTemplate>

                        <asp:TextBox ID="txtLName" runat="Server" Text='<%# Eval("LastName") %>'></asp:TextBox>

                    </EditItemTemplate>

                </asp:TemplateField>

                <asp:TemplateField HeaderText="Age" SortExpression="Age">

                    <ItemTemplate>

                        <%# Eval("Age") %>

                    </ItemTemplate>

                    <EditItemTemplate>

                        <asp:TextBox ID="txtAge" runat="Server" Text='<%# Eval("Age") %>'></asp:TextBox>

                    </EditItemTemplate>

                </asp:TemplateField>

                <asp:TemplateField HeaderText="Delete?">

                    <ItemTemplate>

                        <span onclick="return confirm('Are you sure to Delete?')">

                            <asp:LinkButton ID="lnBD" runat="server" Text="Delete" CommandName="Delete"></asp:LinkButton>

                        </span>

                    </ItemTemplate>

                </asp:TemplateField>

               

            </Columns>

        </asp:GridView>

    </div>

    </form>
