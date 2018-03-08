/*
* MIT License
*
* Copyright (c) 2018 Denis Rozhkov <denis@rozhkoff.com>
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "stdafx.h"


int main()
{
	Aws::SDKOptions options;
	Aws::InitAPI( options );

	try {
		// var region='us-west-2';
		// var identity_pool_id = 'us-west-2:b0a3b7a2-09b0-4948-80a8-cef75c771c3d';
		// var user_pool_id= 'us-west-2_b7a8Pn960';
		// var client_app_id='4o3caaqt0dnqfo3m2c5t0i1vck';		//for Cognito App client
		// var identity_provider='cognito-idp.us-west-2.amazonaws.com/'+user_pool_id; //https://cognito-idp.{region}.amazonaws.com/{userPoolId}

		std::string regionId = "us-west-2";
		std::string clientId = "";
		std::string username = "";
		std::string password = "";
		std::string userPoolId = "";		// without region
		std::string identityPoolId = "";	// without region

		awsx::CognitoAuth auth( regionId, clientId );
		auto creds = auth.Authenticate( username, password, userPoolId, identityPoolId );

		if (!creds.GetAWSAccessKeyId().empty()) {
			std::cout << "access key = " << creds.GetAWSAccessKeyId() << std::endl;
		}
	}
	catch (const std::exception & x) {
		std::cerr << x.what() << std::endl;
	}
	catch (...) {
		std::cerr << "error" << std::endl;
	}

	Aws::ShutdownAPI( options );

	return 0;
}
