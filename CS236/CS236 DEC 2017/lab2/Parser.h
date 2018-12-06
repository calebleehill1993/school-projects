/*
Michael Bruno, Section 002, Michaelbeneamatobruno@gmail.com
Purpose: Parses the list of tokens given by the Lexer, also stores a DatalogProgram and outputs the string.
Inputs: A vector of Tokens via the constructor
Outputs: outputs the DatalogProgram as a string.
*/

#include <iostream>
#include "DatalogProgram.h"
#include "Expression.h"

using namespace std;

class Parser
{

protected:
  vector<Token> myParseTokens;
  int index = 0;
  DatalogProgram DLP;

public:
  Parser(vector<Token> parseTokens){
    myParseTokens = parseTokens;
  }
  ~Parser(){}
  Token getNextToken(tokenType expectedToken) {
    if (expectedToken != myParseTokens.at(index).getTokenType()) {
      throw myParseTokens.at(index);
    }
    else {
      return myParseTokens.at(index++);
    }
  }
  void parseSchemes() {
    getNextToken(SCHEMES);
    getNextToken(COLON);
    if (myParseTokens.at(index).getTokenType() == FACTS) {
      throw (myParseTokens.at(index));
    }
    while (myParseTokens.at(index).getTokenType() != FACTS) {
        parseScheme();
    }
  }
  void parseScheme() {
    Scheme scheme;
    scheme.setId(getNextToken(ID));
    getNextToken(LEFT_PAREN);
    scheme.addId(getNextToken(ID));
    while (myParseTokens.at(index).getTokenType() != RIGHT_PAREN) {
      getNextToken(COMMA);
      scheme.addId(getNextToken(ID));
    }
    getNextToken(RIGHT_PAREN);
    DLP.addToSchemes(scheme);
  }
  void parseFacts() {
    Domain domain;
    getNextToken(FACTS);
    getNextToken(COLON);
    while (myParseTokens.at(index).getTokenType() != RULES) {
      domain.addDomain(parseFact());
    }
    DLP.setDomain(domain);
  }
  Domain parseFact() {
    Fact fact;
    Domain domain;
    Token t;
    fact.setString(getNextToken(ID));
    getNextToken(LEFT_PAREN);
    t = getNextToken(STRING);
    fact.addString(t);
    domain.addString(t.getString());
    while (myParseTokens.at(index).getTokenType() != RIGHT_PAREN) {
      getNextToken(COMMA);
      t = getNextToken(STRING);
      fact.addString(t);
      domain.addString(t.getString());
    }
    getNextToken(RIGHT_PAREN);
    getNextToken(PERIOD);
    DLP.addToFacts(fact);
    return domain;
  }
  void parseRule() {
    Rule rule;
    rule.setHead(grabPredicate());//while loop that acts like parseFacts)
    getNextToken(COLON_DASH);
    rule.addPredicate(grabPredicate());
    while (myParseTokens.at(index).getTokenType() != PERIOD) {
      getNextToken(COMMA);
      rule.addPredicate(grabPredicate());
    }
    getNextToken(PERIOD);
    DLP.addToRules(rule);
  }
  Predicate grabPredicate() {
    Predicate predicate;
    predicate.setString(getNextToken(ID).getString());
    getNextToken(LEFT_PAREN);
    predicate.addParameter(getNextParameter());
    while (myParseTokens.at(index).getTokenType() != RIGHT_PAREN) {
      getNextToken(COMMA);
      predicate.addParameter(getNextParameter());
    }
    getNextToken(RIGHT_PAREN);
    return predicate;
  }
  Parameter getNextParameter() {
    if (myParseTokens.at(index).getTokenType() == LEFT_PAREN) {
      return getExpression();
    }
    else if(myParseTokens.at(index).getTokenType() != ID && myParseTokens.at(index).getTokenType() != STRING) {
      throw myParseTokens.at(index);
    }
    else {
      return myParseTokens.at(index++);
    }
  }
  Expression getExpression() {
    int numOpen = 1;
    stringstream ss;
    ss << myParseTokens.at(index).getString();
    getNextToken(LEFT_PAREN);
    while (numOpen != 0) {
      ss << myParseTokens.at(index).getString();
      if (myParseTokens.at(index).getTokenType() == LEFT_PAREN) {
        numOpen++;
      }
      else if (myParseTokens.at(index).getTokenType() == RIGHT_PAREN) {
        numOpen--;
      }
      index++;
    }
    Expression expression(ss.str());
    return expression;
  }
  void parseRules() {
    getNextToken(RULES);
    getNextToken(COLON);
    while (myParseTokens.at(index).getTokenType() != QUERIES) {
      parseRule();
    }
  }
  void parseQueries() {
    getNextToken(QUERIES);
    getNextToken(COLON);
    Query query;
    if (myParseTokens.at(index).getTokenType() == END_OF_FILE) {
      throw (myParseTokens.at(index));
    }
    while (myParseTokens.at(index).getTokenType() != END_OF_FILE) {
      query = Query(grabPredicate());
      DLP.addToQueries(query);
      getNextToken(Q_MARK);
    }
  }
  int parse() {
    for (int i = 0; i < myParseTokens.size(); i++) {
      if (myParseTokens.at(i).getTokenType() == COMMENT) {
        myParseTokens.erase(myParseTokens.begin() + i);
        i--;
      }
    }
    try {
      parseSchemes();
      parseFacts();
      parseRules();
      parseQueries();
      cout << "Success!" << endl;
      cout << DLP.toString();
    }
    catch (Token errorToken) {
      cout << "Failure!" << endl;
      cout << errorToken.toString();
    }
    return 0;
  }
};
