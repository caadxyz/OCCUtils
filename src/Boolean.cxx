#include "occutils/Boolean.hxx"
#include "occutils/ListUtils.hxx"
#include <BRepAlgoAPI_Fuse.hxx>

using namespace OCCUtils;

TopoDS_Shape OCCUtils::Boolean::Fuse(const TopTools_ListOfShape& arguments, const TopTools_ListOfShape& tools) {
    // Configure fuse
    BRepAlgoAPI_Fuse fuse;
    fuse.SetArguments(arguments);
    fuse.SetTools(tools);
    // Run fuse
    fuse.Build();
    return fuse.Shape(); // Raises NotDone if not done.
}

TopoDS_Shape OCCUtils::Boolean::Fuse(const TopTools_ListOfShape& shapes) {
    // We need "tools" and "arguments".
    // For fuse, the exact split does not matter,
    // but each must be size >= 1!
    auto toolsAndArgs = ListUtils::SplitIntoHeadAndTail(shapes, 1);
    return Fuse(toolsAndArgs.second, toolsAndArgs.first);
}