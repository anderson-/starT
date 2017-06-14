.PHONY: test_nearley

test_nearley: compile_grammar
	node tests/test_nearley.js

compile_grammar:
	nearleyc src/starT.ne > src/starTgrammar.js
