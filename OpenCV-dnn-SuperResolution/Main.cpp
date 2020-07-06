#include <iostream>
#include <fstream>
#include <string>

#include <opencv2/dnn_superres.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


#include "ini.hpp"
#include "MyUtils.hpp"

using namespace std;
using namespace cv;
using namespace dnn;
using namespace dnn_superres;

int main(int argc, char* argv[])
{
	try
	{
		// Read cinfiguration values
		cout << "Reading configuration......" << endl;
		std::map<std::string, std::string>  cf = readVairValues(CONF_CONFIGURATION_FILE, CONF_FILE_SEPARATOR);


		//Create the module object
		DnnSuperResImpl sr;


		// Read image to upscale
		Mat img = cv::imread(cf[CONF_IMAGEN_INPUT]);


		//Read model and set scale to get correct pre- and post-processing
		cout << "Reading model......" << endl;
		sr.readModel(cf[CONF_MODELS_PATH] + "/" + cf[CONF_MODEL_FILE]);
		sr.setModel(cf[CONF_MODEL_TYPE], std::stoi(cf[CONF_SCALE]));


		//Upscale
		cout << "Upscaling image......" << endl;
		Mat img_upscaled;
		sr.upsample(img, img_upscaled);


		// Save upscaled
		cout << "Saving image......" << endl;
		cv::imwrite(cf[CONF_IMAGE_OUTPUT], img_upscaled);

		return 0;

	}
	catch (const std::exception e)
	{
		cout << "Error!!!" << endl;
		system("Pause");
	}

}

