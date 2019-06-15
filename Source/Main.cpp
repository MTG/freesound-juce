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
	std::cout << client.exchangeToken(authCode);
	std::cout << client.refreshAccessToken();


	SoundList list = client.textSearch("bass");
	std::cout << list.getResults().size();
	list = client.fetchNextPage(list);

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

	return 1;
}


int main (int argc, char* argv[])
{

    // ..your code goes here!

	String secret = "xlMDWbwEp65jNneniFiwNe3u7aKyxBPKrxug05KC";
	String id = "qtRxJcdBeEqAPPymT71w";

	//testAuthBrowser(id, secret);
	searchWithToken(secret);


    return 1;
}
