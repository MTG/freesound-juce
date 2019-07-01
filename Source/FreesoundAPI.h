/*
  ==============================================================================

    FreesoundAPI.h
    Created: 30 May 2019 12:49:28pm
    Author:  Antonio

  ==============================================================================
*/

//Todo - Comments

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

typedef std::pair<int, var> Response;
typedef std::function<void()> AuthorizationCallback;

class SoundList {
private:
	int count;
	String nextPage;
	String previousPage;
	var results;
public:

	SoundList();
	SoundList(var response);

	String getNextPage();
	String getPreviousPage();

	var getResults();

};

class URIS {

public:

	static String HOST;
	static String BASE;
	static String TEXT_SEARCH;
	static String CONTENT_SEARCH;
	static String COMBINED_SEARCH;
	static String SOUND;
	static String SOUND_ANALYSIS;
	static String SIMILAR_SOUNDS;
	static String COMMENTS;
	static String DOWNLOAD;
	static String UPLOAD;
	static String DESCRIBE;
	static String PENDING;
	static String BOOKMARK;
	static String RATE;
	static String COMMENT;
	static String AUTHORIZE;
	static String LOGOUT;
	static String LOGOUT_AUTHORIZE;
	static String ACCESS_TOKEN;
	static String ME;
	static String USER;
	static String USER_SOUNDS;
	static String USER_PACKS;
	static String USER_BOOKMARK_CATEGORIES;
	static String USER_BOOKMARK_CATEGORY_SOUNDS;
	static String PACK;
	static String PACK_SOUNDS;
	static String PACK_DOWNLOAD;
	static String CONFIRMATION;

	URIS(){
	}

	~URIS() {
	}

	static URL uri(String uri, StringArray replacements = StringArray());
};

class FSUser {
private:
	URL profile;
	String username;
	String about;
	URL homepage;
	var avatar;
	String dateJoined;
	int numSounds;
	SoundList sounds;
	int numPacks;
	//URL packs;
	int numPosts;
	int numComments;   
	//URL bookmarks

public:
	FSUser();
	FSUser(String username);
};

class FSSound {
//public for now, should create custom get and set methods for each
private:
	int id;
	URL url;
	String name;
	StringArray tags;
	String description;
	String geotag;
	String created;
	String license;
	String format;
	int channels;
	int filesize;
	int bitrate;
	int bitdepth;
	int duration;
	int samplerate;
	String user;
	URL pack;
	URL download;
	URL bookmark;
	var images;
	int numDownloads;
	float avgRating;
	int numRatings;
	URL rate;
	URL comments;
	int numComments;
	URL comment;
	URL similarSounds;
	var analysis;
	URL analysisStats;
	URL analysisFrames;
	var acAnalysis;

public:
	FSSound();
	FSSound(var sound);
};






class FreesoundClient{
	
private:


	enum Authorization
	{
		None,
		Token,
		OAuth
	};

	String token;
	String clientID;
	String clientSecret;
	String accessToken;
	String refreshToken;
	String header;
	Authorization auth;


public:
	FreesoundClient();
	//For token based authorization
	FreesoundClient(String secret);
	//For OAuth2 authorization
	FreesoundClient(String id, String secret);
	bool authenticationOnBrowser(int mode=0);
	int exchangeToken(String authCode);
	int refreshAccessToken();
	SoundList textSearch(String query, String filter=String(), String sort="score", int groupByPack=0, int page=-1, int pageSize=-1, String fields = String(), String descriptors = String(), int normalized=0);
	SoundList contentSearch(String target, String descriptorsFilter=String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);
	//SoundList contentSearchFile(File analysisFile, String descriptorsFilter, int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);
	SoundList fetchNextPage(SoundList soundList);
	SoundList fetchPreviousPage(SoundList soundList);
	FSSound getSound(String id);
	var getSoundAnalysis(String id, String descriptors = String(), int normalized = 0);
	SoundList getSimilarSounds(String id, String descriptorsFilter = String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);
	bool isTokenNotEmpty();
	String getToken();
	String getHeader();
	String getClientID();


};

class FreesoundClientComponent : public FreesoundClient, public WebBrowserComponent {
private:
	AuthorizationCallback authCallback;
	String authCode;
public:
	bool startAuthentication(int mode = 0);
	void setAuthCallback(AuthorizationCallback cb);
	void pageFinishedLoading(const String & url);
	void pageLoadHadNetworkError();

};



class FSRequest {
public:
	FSRequest(URL uriToRequest, FreesoundClient clientToUse)
		:client(clientToUse),
		uri(uriToRequest)
	{}
	
	Response request(StringPairArray params = StringPairArray(), String data = String(), bool postLikeRequest = true);

private:
	URL uri;
	FreesoundClient& client;
};

class FreesoundObject {
public:
	FreesoundObject(var inJsonDict, FreesoundClient& inClient)
		:client(inClient),
		jsonDict(inJsonDict)
	{}
private:
	FreesoundClient& client;
	var jsonDict;

};

