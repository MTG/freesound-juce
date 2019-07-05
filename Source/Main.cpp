/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "FreesoundAPI.h"

//==============================================================================

//Browser based authentication
int testAuthBrowser(String id, String secret) {
	FreesoundClient client(id, secret);
	client.authenticationOnBrowser();
	std::string authCode;
	std::cout << "Insert authorization code:\n";
	std::cin >> authCode;
	String sAuthCode(authCode);
	client.exchangeToken(authCode);


	return 1;
}

int searchWithToken(String secret) {
	FreesoundClient client(secret);
	SoundList list = client.textSearch("bass");
	std::cout << list.getResults().size();
	list = client.fetchNextPage(list);
	list = client.fetchPreviousPage(list);
	var results = list.getResults();
	std::cout << JSON::toString(results);

	//Adicionar parametros extra na pesquisa
	list = client.textSearch("alarm", "tag:guitar", "score", 0, -1, -1, "name,previews,analysis", "lowlevel.spectral_centroid.mean,lowlevel.pitch.mean");
	std::cout << list.getResults().size();
	results = list.getResults();
	std::cout << JSON::toString(results);

	FSSound sound(results[1]);

	return 1;
}


int main (int argc, char* argv[])
{
	argc;
	argv;
    // ..your code goes here!

	String secret = "xlMDWbwEp65jNneniFiwNe3u7aKyxBPKrxug05KC";
	String id = "qtRxJcdBeEqAPPymT71w";

	//testAuthBrowser(id, secret);
	searchWithToken(secret);


    return 1;
}
