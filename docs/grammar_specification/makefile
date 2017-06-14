.PHONY: test_nearley

test_nearley: compile_grammar
	node tests/test_nearley0.2.js

compile_grammar:
	nearleyc src/starTv0.2.ne > src/starTgrammar.js

test_ohm:
	node tests/test_ohm.js
