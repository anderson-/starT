.PHONY: test

test-pico:
	make -C variants/pico/ test

target-arduino-size:
	ln -s ../../../variants/pico/src/ targets/arduino/libraries/star_t
	make -C targets/arduino/ size
	make -C targets/arduino/ clean
	unlink targets/arduino/libraries/star_t

generate_diagrams:
	make -C docs/grammar_specification generate_diagrams
