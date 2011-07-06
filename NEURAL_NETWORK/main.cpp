//standard libraries
#include <iostream>
#include <sstream>

//custom includes
#include "dataEntry.h"
#include "dataReader.h"
#include "neuralNetwork.h"

//use standard namespace
using namespace std;

int  main()
{	
	//create data set reader
	dataReader d;

	//load data file
	d.loadDataFile("vowel-recognition.csv",16,1);
	d.setCreationApproach( STATIC );

	//create neural network
	neuralNetwork nn(16, 8, 1);
	nn.enableLogging("trainingResults.csv");
	nn.setLearningParameters(0.01, 0.8);
	nn.setDesiredAccuracy(100);
	nn.setMaxEpochs(500);
	
	//dataset
	dataSet* dset;		

	for ( int i=0; i < d.nDataSets(); i++ )
	{
		dset = d.getDataSet();	
		nn.trainNetwork( dset->trainingSet, dset->generalizationSet, dset->validationSet );
	}	
	
	cout << "-- END OF PROGRAM --" << endl;

	char c; cin >> c;

return 0;

}

