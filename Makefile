test: test-native test-pure

test-native:
	node-gyp clean
	node-gyp configure build
	node test.js

test-pure:
	node-gyp clean
	node test.js

node_gyp: clean
	node-gyp configure build

clean:
	node-gyp clean

.PHONY: all
