.PHONY: test_grammar

test_grammar: compile_grammar
	node tests/test_grammar.js

compile_grammar:
	nearleyc src/starT.ne > src/starTgrammar.js
