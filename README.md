# ReasonClock

> This is a React Native application developed in Reason.

## Installation

To get started, add the following scripts to your `package.json`:

```json
"scripts": {
  "start": "node node_modules/react-native/local-cli/cli.js start",
  "build": "bsb -make-world -clean-world",
  "watch": "bsb -make-world -clean-world -w"
}
```

Next, run `watch` and `start` scripts from the command line so that both processes are running at the same time. This can be done with `yarn` (e.g. `yarn watch`) or `npm` (e.g. `npm run watch`).

The first script compiles you Reason code in a watch mode, meaning that every change is instantly recompiled.

Second one is a React Native packager that serves the compiled Reason code to the React Native client.

## Color guide

https://www.palettable.io/FFA500-524078-91006F-B30065
