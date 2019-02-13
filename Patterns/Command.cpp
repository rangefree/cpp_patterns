#include "Command.h"


void testCommand()
{
	Action a1("put(File1)");
	Action a2("put(File2)");
	Action a3("finalize()"), bad_action("finalize()", false);

	//KEEP Track of the order:
	{
		cout << "Successful install:\n";
		Installer i;
		i.doCommand(new InstallAction(&a1));
		i.doCommand(new InstallAction(&a2));
		i.doCommand(new InstallAction(&a3));
	}

	cout << endl;
	{
		cout << "Bad install:\n";
		Installer i;
		i.doCommand(new InstallAction(&a1));
		i.doCommand(new InstallAction(&a2));
		i.doCommand(new InstallAction(&bad_action));
	}

}