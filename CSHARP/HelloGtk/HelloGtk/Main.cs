using System;
using Gtk;

namespace HelloGtk
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Application.Init ();
			System.Console.WriteLine ("Hello World from mono");
			MainWindow win = new MainWindow ();
			win.Show ();
			Application.Run ();
		}
	}
}
