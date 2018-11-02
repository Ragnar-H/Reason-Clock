open BsReactNative;

let windowDimensions = Dimensions.get(`window);
let screenHeight = windowDimensions##height;
type option = {
  value: string,
  key: string,
};

let elementHeight = 30;
let elementDiff = index => float_of_int(elementHeight * index);
module Styles = {
  open Style;

  let container = animatedVal =>
    style([
      bottom(Pt(float_of_int(screenHeight / 2))),
      marginHorizontal(Pt(24.)),
      padding(Pt(8.)),
      alignSelf(FlexEnd),
      flexDirection(Column),
      backgroundColor(String("#91006F")),
      borderRadius(5.),
      Transform.makeAnimated(~translateY=animatedVal, ()),
    ]);

  let text =
    style([
      height(Pt(float_of_int(elementHeight))),
      color(String("#ffa500")),
      fontSize(Float(18.)),
      textAlign(Center),
      textAlignVertical(Bottom),
      borderRadius(5.),
      padding(Pt(4.)),
      overflow(Hidden),
    ]);

  let selectedValue = style([backgroundColor(String("#fefefe"))]);
};

let textStyle = is_current =>
  is_current ? Style.combine(Styles.selectedValue, Styles.text) : Styles.text;

let animateToIndex = (animatedVal, index) =>
  Animated.start(
    Animated.spring(
      ~value=animatedVal,
      ~toValue=`raw(elementDiff(index)),
      ~useNativeDriver=true,
      (),
    ),
    ~callback=_didFinish => (),
    (),
  );

type state = {
  selectedValue: string,
  offSetY: Animated.Value.t,
};
type action =
  | UpdatedValue(string);

let component = ReasonReact.reducerComponent("Numbers");

let make = (~options, ~selectedValue, _children) => {
  ...component, /* spread the template's other defaults into here  */
  initialState: () => {
    selectedValue: "",
    offSetY: Animated.Value.create(0.0),
  },
  reducer: (action, state) =>
    switch (action) {
    | UpdatedValue(value) =>
      ReasonReact.Update({...state, selectedValue: value})
    },
  didUpdate: ({oldSelf, newSelf}) =>
    if (oldSelf.state.selectedValue != selectedValue) {
      newSelf.send(UpdatedValue(selectedValue));
      animateToIndex(newSelf.state.offSetY, int_of_string(selectedValue));
    },
  render: self =>
    <Animated.View style={Styles.container(self.state.offSetY)}>
      {
        ReasonReact.array(
          Array.of_list(
            List.map(
              option =>
                <Text
                  key={option.key}
                  style={textStyle(selectedValue == option.value)}>
                  {ReasonReact.string(option.value)}
                </Text>,
              options,
            ),
          ),
        )
      }
    </Animated.View>,
};