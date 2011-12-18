package com.minella.easyMock;

public interface UserDao {

		User loadByUsernameAndPassword(String userName, String password);
}
