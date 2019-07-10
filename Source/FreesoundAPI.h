/*
  ==============================================================================

    FreesoundAPI.h
    Created: 30 May 2019 12:49:28pm
    Author:  Antonio

  ==============================================================================
*/


#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

/**
 * \typedef	std::pair<int, var> Response
 *
 * \brief	Defines an alias representing a response for a request 
 */

typedef std::pair<int, var> Response;

/**
 * \typedef	std::function<void()> Callback
 *
 * \brief	Defines an alias representing the callback
 */

typedef std::function<void()> Callback;

/**
 * \class	FSList
 *
 * \brief	List of file systems.
 *
 * \author	Antonio
 * \date	09/07/2019
 */

class FSList {
protected:
	/** \brief	Number of */
	int count;
	/** \brief	The next page */
	String nextPage;
	/** \brief	The previous page */
	String previousPage;
	/** \brief	The results */
	var results;
public:

	/**
	 * \fn	FSList::FSList();
	 *
	 * \brief	Default constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 */

	FSList();

	/**
	 * \fn	FSList::FSList(var response);
	 *
	 * \brief	Constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	response	The response.
	 */

	FSList(var response);

	/**
	 * \fn	String FSList::getNextPage();
	 *
	 * \brief	Gets the next page
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	The next page.
	 */

	String getNextPage();

	/**
	 * \fn	String FSList::getPreviousPage();
	 *
	 * \brief	Gets the previous page
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	The previous page.
	 */

	String getPreviousPage();

	/**
	 * \fn	var FSList::getResults();
	 *
	 * \brief	Gets the results
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	The results.
	 */

	var getResults();

	/**
	 * \fn	int FSList::getCount();
	 *
	 * \brief	Gets the count
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	The count.
	 */

	int getCount();

};

/**
 * \class	URIS
 *
 * \brief	An uris.
 *
 * \author	Antonio
 * \date	09/07/2019
 */

class URIS {

public:

	/** \brief	The host */
	static String HOST;
	/** \brief	The base */
	static String BASE;
	/** \brief	The text search */
	static String TEXT_SEARCH;
	/** \brief	The content search */
	static String CONTENT_SEARCH;
	/** \brief	The combined search */
	static String COMBINED_SEARCH;
	/** \brief	The sound */
	static String SOUND;
	/** \brief	The sound analysis */
	static String SOUND_ANALYSIS;
	/** \brief	The similar sounds */
	static String SIMILAR_SOUNDS;
	/** \brief	The comments */
	static String COMMENTS;
	/** \brief	The download */
	static String DOWNLOAD;
	/** \brief	The upload */
	static String UPLOAD;
	/** \brief	The describe */
	static String DESCRIBE;
	/** \brief	The pending */
	static String PENDING;
	/** \brief	The bookmark */
	static String BOOKMARK;
	/** \brief	The rate */
	static String RATE;
	/** \brief	The comment */
	static String COMMENT;
	/** \brief	The authorize */
	static String AUTHORIZE;
	/** \brief	The logout */
	static String LOGOUT;
	/** \brief	The logout authorize */
	static String LOGOUT_AUTHORIZE;
	/** \brief	The access token */
	static String ACCESS_TOKEN;
	/** \brief	me */
	static String ME;
	/** \brief	The user */
	static String USER;
	/** \brief	The user sounds */
	static String USER_SOUNDS;
	/** \brief	The user packs */
	static String USER_PACKS;
	/** \brief	Categories the user bookmark belongs to */
	static String USER_BOOKMARK_CATEGORIES;
	/** \brief	The user bookmark category sounds */
	static String USER_BOOKMARK_CATEGORY_SOUNDS;
	/** \brief	The pack */
	static String PACK;
	/** \brief	The pack sounds */
	static String PACK_SOUNDS;
	/** \brief	The pack download */
	static String PACK_DOWNLOAD;
	/** \brief	The confirmation */
	static String CONFIRMATION;
	/** \brief	The edit */
	static String EDIT;

	/**
	 * \fn	URIS::URIS()
	 *
	 * \brief	Default constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 */

	URIS(){
	}

	/**
	 * \fn	URIS::~URIS()
	 *
	 * \brief	Destructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 */

	~URIS() {
	}

	/**
	 * \fn	static URL URIS::uri(String uri, StringArray replacements = StringArray());
	 *
	 * \brief	Uris the given document
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	uri				URI of the resource.
	 * \param	replacements	(Optional) The replacements.
	 *
	 * \returns	An URL.
	 */

	static URL uri(String uri, StringArray replacements = StringArray());
};

/**
 * \class	FSUser
 *
 * \brief	A file system user.
 *
 * \author	Antonio
 * \date	09/07/2019
 */

class FSUser {

public:
	/** \brief	The profile */
	URL profile;
	/** \brief	The username */
	String username;
	/** \brief	The about */
	String about;
	/** \brief	The homepage */
	URL homepage;
	/** \brief	The avatar */
	var avatar;
	/** \brief	The date joined */
	String dateJoined;
	/** \brief	Number of sounds */
	int numSounds;
	/** \brief	The sounds */
	URL sounds;
	/** \brief	Number of packs */
	int numPacks;
	/** \brief	The packs */
	URL packs;
	/** \brief	Number of posts */
	int numPosts;
	/** \brief	Number of comments */
	int numComments;   
	/** \brief	The bookmarks */
	URL bookmarks;

	/**
	 * \fn	FSUser::FSUser();
	 *
	 * \brief	Default constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 */

	FSUser();

	/**
	 * \fn	FSUser::FSUser(var user);
	 *
	 * \brief	Constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	user	The user.
	 */

	FSUser(var user);
};

/**
 * \class	FSPack
 *
 * \brief	A file system pack.
 *
 * \author	Antonio
 * \date	09/07/2019
 */

class FSPack {

public:
	/** \brief	The identifier */
	String id;
	/** \brief	URL of the resource */
	URL url;
	/** \brief	The description */
	String description;
	/** \brief	The created */
	String created;
	/** \brief	The name */
	String name;
	/** \brief	The username */
	String username;
	/** \brief	Number of sounds */
	int numSounds;
	/** \brief	The sounds */
	URL sounds;
	/** \brief	Number of downloads */
	int numDownloads;

	/**
	 * \fn	FSPack::FSPack();
	 *
	 * \brief	Default constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 */

	FSPack();

	/**
	 * \fn	FSPack::FSPack(var pack);
	 *
	 * \brief	Constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	pack	The pack.
	 */

	FSPack(var pack);

	/**
	 * \fn	String FSPack::getID();
	 *
	 * \brief	Gets the identifier
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	The identifier.
	 */

	String getID();
};

/**
 * \class	FSSound
 *
 * \brief	A file system sound.
 *
 * \author	Antonio
 * \date	09/07/2019
 */

class FSSound {
public:
	/** \brief	The identifier */
	String id;
	/** \brief	URL of the resource */
	URL url;
	/** \brief	The name */
	String name;
	/** \brief	The tags */
	StringArray tags;
	/** \brief	The description */
	String description;
	/** \brief	The geotag */
	String geotag;
	/** \brief	The created */
	String created;
	/** \brief	The license */
	String license;
	/** \brief	Describes the format to use */
	String format;
	/** \brief	The channels */
	int channels;
	/** \brief	The filesize */
	int filesize;
	/** \brief	The bitrate */
	int bitrate;
	/** \brief	The bitdepth */
	int bitdepth;
	/** \brief	The duration */
	int duration;
	/** \brief	The samplerate */
	int samplerate;
	/** \brief	The user */
	String user;
	/** \brief	The pack */
	URL pack;
	/** \brief	The download */
	URL download;
	/** \brief	The bookmark */
	URL bookmark;
	/** \brief	The images */
	var images;
	/** \brief	Number of downloads */
	int numDownloads;
	/** \brief	The average rating */
	float avgRating;
	/** \brief	Number of ratings */
	int numRatings;
	/** \brief	The rate */
	URL rate;
	/** \brief	The comments */
	URL comments;
	/** \brief	Number of comments */
	int numComments;
	/** \brief	The comment */
	URL comment;
	/** \brief	The similar sounds */
	URL similarSounds;
	/** \brief	The analysis */
	var analysis;
	/** \brief	The analysis statistics */
	URL analysisStats;
	/** \brief	The analysis frames */
	URL analysisFrames;
	/** \brief	The AC analysis */
	var acAnalysis;

	/**
	 * \fn	FSSound::FSSound();
	 *
	 * \brief	Default constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 */

	FSSound();

	/**
	 * \fn	FSSound::FSSound(var sound);
	 *
	 * \brief	Constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	sound	The sound.
	 */

	FSSound(var sound);

	/**
	 * \fn	URL FSSound::getDownload();
	 *
	 * \brief	Gets the download
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	The download.
	 */

	URL getDownload();
};

/**
 * \class	SoundList
 *
 * \brief	List of sounds.
 *
 * \author	Antonio
 * \date	09/07/2019
 */

class SoundList : public FSList {
	using FSList::FSList;
public:

	/**
	 * \fn	Array<FSSound> SoundList::toArrayOfSounds();
	 *
	 * \brief	Converts this object to an array of sounds
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	This object as an Array&lt;FSSound&gt;
	 */

	Array<FSSound> toArrayOfSounds();
};

/**
 * \class	FreesoundClient
 *
 * \brief	A freesound client.
 *
 * \author	Antonio
 * \date	09/07/2019
 */

class FreesoundClient{
	
private:

	/**
	 * \enum	Authorization
	 *
	 * \brief	Values that represent authorizations
	 */

	enum Authorization
	{
		None,
		Token,
		OAuth
	};

	/** \brief	The token */
	String token;
	/** \brief	Identifier for the client */
	String clientID;
	/** \brief	The client secret */
	String clientSecret;
	/** \brief	The access token */
	String accessToken;
	/** \brief	The refresh token */
	String refreshToken;
	/** \brief	The header */
	String header;
	/** \brief	The authentication */
	Authorization auth;


public:

	/**
	 * \fn	FreesoundClient::FreesoundClient();
	 *
	 * \brief	Default constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 */

	FreesoundClient();
	//For token based authorization

	/**
	 * \fn	FreesoundClient::FreesoundClient(String secret);
	 *
	 * \brief	Constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	secret	The secret.
	 */

	FreesoundClient(String secret);
	//For OAuth2 authorization

	/**
	 * \fn	FreesoundClient::FreesoundClient(String id, String secret);
	 *
	 * \brief	Constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	id	  	The identifier.
	 * \param	secret	The secret.
	 */

	FreesoundClient(String id, String secret);

	/**
	 * \fn	void FreesoundClient::authenticationOnBrowser(int mode=0, Callback cb = [] {});
	 *
	 * \brief	Authentication browser
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	mode	(Optional) The mode.
	 * \param	cb  	(Optional) The cb.
	 */

	void authenticationOnBrowser(int mode=0, Callback cb = [] {});

	/**
	 * \fn	void FreesoundClient::exchangeToken(String authCode, Callback cb = [] {});
	 *
	 * \brief	Exchange token
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	authCode	The authentication code.
	 * \param	cb			(Optional) The cb.
	 */

	void exchangeToken(String authCode, Callback cb = [] {});

	/**
	 * \fn	void FreesoundClient::refreshAccessToken(Callback cb = [] {});
	 *
	 * \brief	Refresh access token
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	cb	(Optional) The cb.
	 */

	void refreshAccessToken(Callback cb = [] {});

	/**
	 * \fn	SoundList FreesoundClient::textSearch(String query, String filter=String(), String sort="score", int groupByPack=0, int page=-1, int pageSize=-1, String fields = String(), String descriptors = String(), int normalized=0);
	 *
	 * \brief	Text search
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	query	   	The query.
	 * \param	filter	   	(Optional) Specifies the filter.
	 * \param	sort	   	(Optional) The sort.
	 * \param	groupByPack	(Optional) The group by pack.
	 * \param	page	   	(Optional) The page.
	 * \param	pageSize   	(Optional) Size of the page.
	 * \param	fields	   	(Optional) The fields.
	 * \param	descriptors	(Optional) The descriptors.
	 * \param	normalized 	(Optional) The normalized.
	 *
	 * \returns	A SoundList.
	 */

	SoundList textSearch(String query, String filter=String(), String sort="score", int groupByPack=0, int page=-1, int pageSize=-1, String fields = String(), String descriptors = String(), int normalized=0);

	/**
	 * \fn	SoundList FreesoundClient::contentSearch(String target, String descriptorsFilter=String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);
	 *
	 * \brief	Content search
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	target			 	Target for the.
	 * \param	descriptorsFilter	(Optional) A filter specifying the descriptors.
	 * \param	page			 	(Optional) The page.
	 * \param	pageSize		 	(Optional) Size of the page.
	 * \param	fields			 	(Optional) The fields.
	 * \param	descriptors		 	(Optional) The descriptors.
	 * \param	normalized		 	(Optional) The normalized.
	 *
	 * \returns	A SoundList.
	 */

	SoundList contentSearch(String target, String descriptorsFilter=String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);

	/**
	 * \fn	SoundList FreesoundClient::fetchNextPage(SoundList soundList);
	 *
	 * \brief	Fetches next page
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	soundList	List of sounds.
	 *
	 * \returns	The next page.
	 */

	SoundList fetchNextPage(SoundList soundList);

	/**
	 * \fn	SoundList FreesoundClient::fetchPreviousPage(SoundList soundList);
	 *
	 * \brief	Fetches previous page
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	soundList	List of sounds.
	 *
	 * \returns	The previous page.
	 */

	SoundList fetchPreviousPage(SoundList soundList);

	/**
	 * \fn	FSSound FreesoundClient::getSound(String id);
	 *
	 * \brief	Gets a sound
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	id	The identifier.
	 *
	 * \returns	The sound.
	 */

	FSSound getSound(String id);

	/**
	 * \fn	var FreesoundClient::getSoundAnalysis(String id, String descriptors = String(), int normalized = 0);
	 *
	 * \brief	Gets sound analysis
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	id		   	The identifier.
	 * \param	descriptors	(Optional) The descriptors.
	 * \param	normalized 	(Optional) The normalized.
	 *
	 * \returns	The sound analysis.
	 */

	var getSoundAnalysis(String id, String descriptors = String(), int normalized = 0);

	/**
	 * \fn	SoundList FreesoundClient::getSimilarSounds(String id, String descriptorsFilter = String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);
	 *
	 * \brief	Gets similar sounds
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	id				 	The identifier.
	 * \param	descriptorsFilter	(Optional) A filter specifying the descriptors.
	 * \param	page			 	(Optional) The page.
	 * \param	pageSize		 	(Optional) Size of the page.
	 * \param	fields			 	(Optional) The fields.
	 * \param	descriptors		 	(Optional) The descriptors.
	 * \param	normalized		 	(Optional) The normalized.
	 *
	 * \returns	The similar sounds.
	 */

	SoundList getSimilarSounds(String id, String descriptorsFilter = String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);

	/**
	 * \fn	URL::DownloadTask* FreesoundClient::downloadSound(FSSound sound, const File &location, URL::DownloadTask::Listener * listener = nullptr);
	 *
	 * \brief	Downloads the sound
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param 		  	sound   	The sound.
	 * \param 		  	location	The location.
	 * \param [in,out]	listener	(Optional) If non-null, the listener.
	 *
	 * \returns	Null if it fails, else a pointer to an URL::DownloadTask.
	 */

	URL::DownloadTask* downloadSound(FSSound sound, const File &location, URL::DownloadTask::Listener * listener = nullptr);

	/**
	 * \fn	int FreesoundClient::uploadSound(const File &fileToUpload, String tags, String description, String name = String(), String license = "Creative Commons 0", String pack = String(), String geotag = String(), Callback cb = [] {});
	 *
	 * \brief	Uploads a sound
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	fileToUpload	The file to upload.
	 * \param	tags			The tags.
	 * \param	description 	The description.
	 * \param	name			(Optional) The name.
	 * \param	license			(Optional) The license.
	 * \param	pack			(Optional) The pack.
	 * \param	geotag			(Optional) The geotag.
	 * \param	cb				(Optional) The cb.
	 *
	 * \returns	An int.
	 */

	int uploadSound(const File &fileToUpload, String tags, String description, String name = String(), String license = "Creative Commons 0", String pack = String(), String geotag = String(), Callback cb = [] {});

	/**
	 * \fn	int FreesoundClient::describeSound(String uploadFilename, String description, String license, String name = String(), String tags = String(), String pack = String(), String geotag = String() );
	 *
	 * \brief	Describe sound
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	uploadFilename	Filename of the upload file.
	 * \param	description   	The description.
	 * \param	license		  	The license.
	 * \param	name		  	(Optional) The name.
	 * \param	tags		  	(Optional) The tags.
	 * \param	pack		  	(Optional) The pack.
	 * \param	geotag		  	(Optional) The geotag.
	 *
	 * \returns	An int.
	 */

	int describeSound(String uploadFilename, String description, String license, String name = String(), String tags = String(), String pack = String(), String geotag = String() );

	/**
	 * \fn	var FreesoundClient::pendingUploads();
	 *
	 * \brief	Pending uploads
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	A var.
	 */

	var pendingUploads();

	/**
	 * \fn	void FreesoundClient::editSoundDescription(String id, String name = String(), String tags = String(), String description = String(), String license = String(), String pack = String(), String geotag = String(), Callback cb = [] {});
	 *
	 * \brief	Edit sound description
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	id		   	The identifier.
	 * \param	name	   	(Optional) The name.
	 * \param	tags	   	(Optional) The tags.
	 * \param	description	(Optional) The description.
	 * \param	license	   	(Optional) The license.
	 * \param	pack	   	(Optional) The pack.
	 * \param	geotag	   	(Optional) The geotag.
	 * \param	cb		   	(Optional) The cb.
	 */

	void editSoundDescription(String id, String name = String(), String tags = String(), String description = String(), String license = String(), String pack = String(), String geotag = String(), Callback cb = [] {});

	/**
	 * \fn	void FreesoundClient::bookmarkSound(String id, String name = String(), String category = String(), Callback cb = [] {});
	 *
	 * \brief	Bookmark sound
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	id			The identifier.
	 * \param	name		(Optional) The name.
	 * \param	category	(Optional) The category.
	 * \param	cb			(Optional) The cb.
	 */

	void bookmarkSound(String id, String name = String(), String category = String(), Callback cb = [] {});

	/**
	 * \fn	void FreesoundClient::rateSound(String id, int rating, Callback cb = [] {});
	 *
	 * \brief	Rate sound
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	id	  	The identifier.
	 * \param	rating	The rating.
	 * \param	cb	  	(Optional) The cb.
	 */

	void rateSound(String id, int rating, Callback cb = [] {});

	/**
	 * \fn	void FreesoundClient::commentSound(String id, String comment, Callback cb = [] {});
	 *
	 * \brief	Comment sound
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	id	   	The identifier.
	 * \param	comment	The comment.
	 * \param	cb	   	(Optional) The cb.
	 */

	void commentSound(String id, String comment, Callback cb = [] {});

	/**
	 * \fn	FSUser FreesoundClient::getUser(String user);
	 *
	 * \brief	Gets a user
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	user	The user.
	 *
	 * \returns	The user.
	 */

	FSUser getUser(String user);

	/**
	 * \fn	SoundList FreesoundClient::getUserSounds(String username, String descriptorsFilter = String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);
	 *
	 * \brief	Gets user sounds
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	username		 	The username.
	 * \param	descriptorsFilter	(Optional) A filter specifying the descriptors.
	 * \param	page			 	(Optional) The page.
	 * \param	pageSize		 	(Optional) Size of the page.
	 * \param	fields			 	(Optional) The fields.
	 * \param	descriptors		 	(Optional) The descriptors.
	 * \param	normalized		 	(Optional) The normalized.
	 *
	 * \returns	The user sounds.
	 */

	SoundList getUserSounds(String username, String descriptorsFilter = String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);

	/**
	 * \fn	FSList FreesoundClient::getUserBookmarkCategories(String username);
	 *
	 * \brief	Gets user bookmark categories
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	username	The username.
	 *
	 * \returns	The user bookmark categories.
	 */

	FSList getUserBookmarkCategories(String username);

	/**
	 * \fn	FSList FreesoundClient::getUserBookmarkCategoriesSounds(String username, String bookmarkCategory);
	 *
	 * \brief	Gets user bookmark categories sounds
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	username			The username.
	 * \param	bookmarkCategory	Category the bookmark belongs to.
	 *
	 * \returns	The user bookmark categories sounds.
	 */

	FSList getUserBookmarkCategoriesSounds(String username, String bookmarkCategory);

	/**
	 * \fn	FSList FreesoundClient::getUserPacks(String username);
	 *
	 * \brief	Gets user packs
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	username	The username.
	 *
	 * \returns	The user packs.
	 */

	FSList getUserPacks(String username);

	/**
	 * \fn	FSPack FreesoundClient::getPack(String id);
	 *
	 * \brief	Gets a pack
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	id	The identifier.
	 *
	 * \returns	The pack.
	 */

	FSPack getPack(String id);

	/**
	 * \fn	SoundList FreesoundClient::getPackSounds(String id, String descriptorsFilter = String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);
	 *
	 * \brief	Gets pack sounds
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	id				 	The identifier.
	 * \param	descriptorsFilter	(Optional) A filter specifying the descriptors.
	 * \param	page			 	(Optional) The page.
	 * \param	pageSize		 	(Optional) Size of the page.
	 * \param	fields			 	(Optional) The fields.
	 * \param	descriptors		 	(Optional) The descriptors.
	 * \param	normalized		 	(Optional) The normalized.
	 *
	 * \returns	The pack sounds.
	 */

	SoundList getPackSounds(String id, String descriptorsFilter = String(), int page = -1, int pageSize = -1, String fields = String(), String descriptors = String(), int normalized = 0);

	/**
	 * \fn	URL::DownloadTask* FreesoundClient::downloadPack(FSPack pack, const File &location, URL::DownloadTask::Listener * listener = nullptr);
	 *
	 * \brief	Downloads the pack
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param 		  	pack		The pack.
	 * \param 		  	location	The location.
	 * \param [in,out]	listener	(Optional) If non-null, the listener.
	 *
	 * \returns	Null if it fails, else a pointer to an URL::DownloadTask.
	 */

	URL::DownloadTask* downloadPack(FSPack pack, const File &location, URL::DownloadTask::Listener * listener = nullptr);

	/**
	 * \fn	FSUser FreesoundClient::getMe();
	 *
	 * \brief	Gets me
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	me.
	 */

	FSUser getMe();

	/**
	 * \fn	bool FreesoundClient::isTokenNotEmpty();
	 *
	 * \brief	Queries if the token not is empty
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	True if the token not is empty, false if not.
	 */

	bool isTokenNotEmpty();

	/**
	 * \fn	String FreesoundClient::getToken();
	 *
	 * \brief	Gets the token
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	The token.
	 */

	String getToken();

	/**
	 * \fn	String FreesoundClient::getHeader();
	 *
	 * \brief	Gets the header
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	The header.
	 */

	String getHeader();

	/**
	 * \fn	String FreesoundClient::getClientID();
	 *
	 * \brief	Gets client identifier
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \returns	The client identifier.
	 */

	String getClientID();


};

/**
 * \class	FreesoundClientComponent
 *
 * \brief	A freesound client component.
 *
 * \author	Antonio
 * \date	09/07/2019
 */

class FreesoundClientComponent : public FreesoundClient, public WebBrowserComponent {
private:
	/** \brief	The authentication code */
	String authCode;
public:

	/**
	 * \fn	void FreesoundClientComponent::startAuthentication(int mode = 0);
	 *
	 * \brief	Starts an authentication
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	mode	(Optional) The mode.
	 */

	void startAuthentication(int mode = 0);

	/**
	 * \fn	void FreesoundClientComponent::pageFinishedLoading(const String & url, Callback authCallback = [] {});
	 *
	 * \brief	Page finished loading
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	url				URL of the resource.
	 * \param	authCallback	(Optional) The authentication callback.
	 */

	void pageFinishedLoading(const String & url, Callback authCallback = [] {});

	/**
	 * \fn	void FreesoundClientComponent::pageLoadHadNetworkError();
	 *
	 * \brief	Page load had network error
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 */

	void pageLoadHadNetworkError();

};

/**
 * \class	FSRequest
 *
 * \brief	A file system request.
 *
 * \author	Antonio
 * \date	09/07/2019
 */

class FSRequest {
public:

	/**
	 * \fn	FSRequest::FSRequest(URL uriToRequest, FreesoundClient clientToUse)
	 *
	 * \brief	Constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	uriToRequest	The URI to request.
	 * \param	clientToUse 	The client to use.
	 */

	FSRequest(URL uriToRequest, FreesoundClient clientToUse)
		:client(clientToUse),
		uri(uriToRequest)
	{}

	/**
	 * \fn	Response FSRequest::request(StringPairArray params = StringPairArray(), String data = String(), bool postLikeRequest = true);
	 *
	 * \brief	Requests
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param	params		   	(Optional) Options for controlling the operation.
	 * \param	data		   	(Optional) The data.
	 * \param	postLikeRequest	(Optional) True to post like request.
	 *
	 * \returns	A Response.
	 */

	Response request(StringPairArray params = StringPairArray(), String data = String(), bool postLikeRequest = true);

private:
	/** \brief	URI of the resource */
	URL uri;
	/** \brief	The client */
	FreesoundClient& client;
};

/**
 * \class	FreesoundObject
 *
 * \brief	A freesound object.
 *
 * \author	Antonio
 * \date	09/07/2019
 */

class FreesoundObject {
public:

	/**
	 * \fn	FreesoundObject::FreesoundObject(var inJsonDict, FreesoundClient& inClient)
	 *
	 * \brief	Constructor
	 *
	 * \author	Antonio
	 * \date	09/07/2019
	 *
	 * \param 		  	inJsonDict	Dictionary of in jsons.
	 * \param [in,out]	inClient  	The in client.
	 */

	FreesoundObject(var inJsonDict, FreesoundClient& inClient)
		:client(inClient),
		jsonDict(inJsonDict)
	{}
private:
	/** \brief	The client */
	/** \brief	The client */
	FreesoundClient& client;
	var jsonDict;

};

