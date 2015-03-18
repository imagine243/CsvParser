# CsvParser
Csv file parser

it use for cocos2dx 2.2.3.

parser a csv file to a lot maps.

###usage

	CsvParser * textParser = CsvParser::create("resources/config/tag_text.csv");
    CsvParser * soundParser = CsvParser::create("resources/config/tag_sound.csv");

	
	int textSize =  textParser->size();
	for (int i = 0; i < textSize; i++)
	{
		TextConfig * textConfig = TextConfig::create();
		std::map<std::string, std::string> textMap = textParser->findOne(i);
		
		textConfig->setid(strToInt(textMap.at("ID")));

		int colorR = strToInt(textMap.at("ColorR"));
		int colorG = strToInt(textMap.at("ColorG"));
		int colorB = strToInt(textMap.at("ColorB"));

		textConfig->setbColor(ccc3(colorR,colorG,colorB));

		textConfigArray->addObject(textConfig);
	}