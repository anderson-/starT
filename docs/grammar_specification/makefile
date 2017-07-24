.PHONY: test_grammar

test_grammar: compile_grammar
	NODE_PATH=/usr/local/lib/node_modules \
	node tests/test_grammar.js

compile_grammar:
	nearleyc src/starT.ne > src/starTgrammar.js

clean:
	rm src/starTgrammar.js
	rm syntax_diagrams/syntax.html

generate_diagrams:
	nearley-railroad src/starT.ne -o syntax_diagrams/syntax.html
