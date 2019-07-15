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

//Simple search with token authorization
int searchWithToken(String secret) {
	FreesoundClient client(secret);
	SoundList list = client.textSearch("bass");
	std::cout << list.getResults().size();
	list = client.fetchNextPage(list);
	list = client.fetchPreviousPage(list);
	var results = list.getResults();
	std::cout << JSON::toString(results);

	list = client.textSearch("alarm", "tag:guitar", "score", 0, -1, -1, "name,previews,analysis", "lowlevel.spectral_centroid.mean,lowlevel.pitch.mean");
	std::cout << list.getResults().size();
	results = list.getResults();
	std::cout << JSON::toString(results);

	FSSound sound(results[1]);

	return 1;
}

int testExamples(String id, String secret, bool auth) {
	
	FreesoundClient client;

	//Does either the token authorization (auth==false) or the OAuth2 authorization(auth=true)

	if (auth == true){
		client = FreesoundClient(id, secret);
		client.authenticationOnBrowser(1);
		std::string authCode;
		std::cout << "Insert authorization code:\n";
		std::cin >> authCode;
		String sAuthCode(authCode);
		client.exchangeToken(authCode);
	}
	else {
		client = FreesoundClient(secret);
	}

	//Get sound info example
	FSSound sound = client.getSound("96541");
	std::cout << "Sound name: " << sound.name << std::endl;
	std::cout << "Sound URL: " << sound.url.toString(true) << std::endl;
	std::cout << "Description: " << sound.description << std::endl;
	std::cout << "Sound tags: " << sound.tags.joinIntoString(" ") << std::endl;
	var analysis = client.getSoundAnalysis("96541", "lowlevel.spectral_centroid.mean", 1);
	float spectralCentroid = analysis["lowlevel"]["spectral_centroid"]["mean"];
	std::cout << "Sound Spectral Centroid Mean: " << spectralCentroid << std::endl;

	//Get similar sounds example
	SoundList similarSounds = client.getSimilarSounds(sound.id, "lowlevel.pitch.mean:[110 TO 180]", -1, 10, "name,username,download");
	Array<FSSound> arrayOfSimilarSounds = similarSounds.toArrayOfSounds();
	String name, username;
	for (int i = 0; i < arrayOfSimilarSounds.size(); i++) {
		name = arrayOfSimilarSounds[i].name;
		username = arrayOfSimilarSounds[i].user;
		std::cout << "Sound Name: " << name << " Username: " << username << std::endl;
	}
	
	// Search Example
	std::cout << "Searching for 'violoncello':" << std::endl;
	SoundList textSearch = client.textSearch("violoncello", "tag:tenuto duration:[1.0 TO 15.0]", "rating_desc", 0, -1, -1, "id,name,previews,username,download,type");
	std::cout << "Num results." << textSearch.getCount() << std::endl;
	std::cout << "Page1: " << std::endl;
	Array<FSSound> arrayOfSearch = textSearch.toArrayOfSounds();
	for (int i = 0; i < arrayOfSearch.size(); i++) {
		name = arrayOfSearch[i].name;
		username = arrayOfSearch[i].user;
		std::cout << "Sound Name: " << name << " Username: " << username << std::endl;
	}

	std::cout << "Page2: " << std::endl;
	textSearch = client.fetchNextPage(textSearch);
	arrayOfSearch = textSearch.toArrayOfSounds();
	for (int i = 0; i < arrayOfSearch.size(); i++) {
		name = arrayOfSearch[i].name;
		username = arrayOfSearch[i].user;
		std::cout << "Sound Name: " << name << " Username: " << username << std::endl;
	}

	//Sound download example
	URL::DownloadTask* download;
	download = client.downloadSound(arrayOfSearch[1], File::getSpecialLocation(File::userDesktopDirectory).getChildFile(arrayOfSearch[1].id).withFileExtension(arrayOfSearch[1].format));
	//Content based search example
	std::cout << "Content Based Search" << std::endl;
	SoundList contentSearch = client.contentSearch("lowlevel.pitch_salience.mean:1.0 lowlevel.pitch.mean:440", "lowlevel.pitch.var:[* TO 20]");
	std::cout << "Num results." << contentSearch.getCount() << std::endl;
	arrayOfSearch = contentSearch.toArrayOfSounds();
	for (int i = 0; i < arrayOfSearch.size(); i++) {
		name = arrayOfSearch[i].name;
		username = arrayOfSearch[i].user;
		std::cout << "Sound Name: " << name << " Username: " << username << std::endl;
	}
		
	//Getting sounds from a user example
	std::cout << "User Sounds:" << std::endl;
	FSUser user = client.getUser("Jovica");
	std::cout << "Username:" << user.username << std::endl;
	SoundList userSounds = client.getUserSounds(user.username);
	std::cout << "Num results." << userSounds.getCount() << std::endl;
	arrayOfSearch = userSounds.toArrayOfSounds();
	for (int i = 0; i < arrayOfSearch.size(); i++) {
		name = arrayOfSearch[i].name;
		username = arrayOfSearch[i].user;
		std::cout << "Sound Name: " << name << " Username: " << username << std::endl;
	}

	//Getting sounds from a user example specifying some request parameters
	std::cout << "User Sounds, with parameters:" << std::endl;
	userSounds = client.getUserSounds(user.username, String(), -1,10, "name,username,samplerate,duration,analysis", "rhythm.bpm");
	std::cout << "Num results." << userSounds.getCount() << std::endl;
	arrayOfSearch = userSounds.toArrayOfSounds();
	for (int i = 0; i < arrayOfSearch.size(); i++) {
		name = arrayOfSearch[i].name;
		username = arrayOfSearch[i].user;
		std::cout << "Sound Name: " << name << " Username: " << username << std::endl;
		std::cout << "SampleRate: " << arrayOfSearch[i].samplerate << "Duration: " << arrayOfSearch[i].duration << std::endl;
	}

	// Getting sounds from a pack example specifying some request parameters
	std::cout << "Pack sounds specifying some request parameters:" << std::endl;
	FSPack pack = client.getPack("3524");
	std::cout << "Pack name: " << pack.name << std::endl;
	SoundList packSounds= client.getPackSounds(pack.id);
	arrayOfSearch = packSounds.toArrayOfSounds();
	for (int i = 0; i < arrayOfSearch.size(); i++) {
		name = arrayOfSearch[i].name;
		username = arrayOfSearch[i].user;
		std::cout << "Sound Name: " << name << " Username: " << username << std::endl;
	}
	// Getting bookmark categories from a user example
	std::cout << "User bookmark categories:" << std::endl;
	
	FSUser userBookmark = client.getUser("frederic.font");
	
	FSList bookmarkCategories = client.getUserBookmarkCategories(userBookmark.username);
	std::cout << JSON::toString(bookmarkCategories.getResults());


	delete download;

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
	testExamples(id,secret,true);


    return 1;
}
