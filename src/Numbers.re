open BsReactNative;

type option = {
  value: string,
  key: string,
};
let component = ReasonReact.statelessComponent("Numbers");

let make = (~options, _children) => {
  ...component, /* spread the template's other defaults into here  */
  render: _self =>
    ReasonReact.array(
      Array.map(
        option =>
          <Text key={option.key}> {ReasonReact.string(option.value)} </Text>,
        options,
      ),
    ),
};