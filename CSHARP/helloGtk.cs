
//Compile with: gmcs helloGtk.cs -pkg:gtk-sharp-2.0

//Run with: mono helloGtk.exe

using Gtk;
using System;


class Hello {

	static void Main () {

		Application.Init();
		
		Window window = new Window ("HELLO WORLD FROM MONO");
		window.show();

		Application.Run();	 
	}




}
