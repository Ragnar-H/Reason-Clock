open BsReactNative;

type option = {
  value: string,
  key: string,
};

module Styles = {
  open Style;

  let container =
    style([
      margin(Pt(24.)),
      padding(Pt(8.)),
      flexDirection(Column),
      backgroundColor(String("#91006F")),
    ]);

  let text = style([color(String("#ffa500")), fontSize(Float(24.))]);
};

let component = ReasonReact.statelessComponent("Numbers");

let make = (~options, _children) => {
  ...component, /* spread the template's other defaults into here  */
  render: _self =>
    <View style=Styles.container>
      {
        ReasonReact.array(
          Array.map(
            option =>
              <Text key={option.key} style=Styles.text>
                {ReasonReact.string(option.value)}
              </Text>,
            options,
          ),
        )
      }
    </View>,
};