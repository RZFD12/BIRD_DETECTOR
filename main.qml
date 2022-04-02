import QtQuick 2.15
import QtPositioning 5.15
import QtLocation 5.15

Item {
    id: item
    ListModel {
        id: mymodel
    }
    Map {
        id: map
        anchors.fill: parent
        plugin: Plugin {
            name: "osm"
        }
        center: QtPositioning.coordinate(56.3287, 44.002)
        zoomLevel: 6
        activeMapType: supportedMapTypes[3]
        MapItemView {
            z: polygon.z + 1
            model: mymodel
            delegate: MapCircle {
                radius: model.radius
                opacity: 0.5
                border.width: 3
                color: 'green'
                center: QtPositioning.coordinate(model.coords.latitude,
                                                 model.coords.longitude)
            }
        }
        MapPolygon {
            id: polygon
            border.width: 0
        }
    }
    function moveMarker(index, coordinate) {
        mymodel.set(index, {
                        "coords": coordinate
                    })
        var path = polygon.path
        path[index] = coordinate
        polygon.path = path
    }
    function addMarker(coordinate) {
        mymodel.append({
                           "coords": coordinate
                       })
        polygon.addCoordinate(coordinate)
    }
    function delMarkers(index, coordinate) {
        mymodel.clear()
        polygon.removeCoordinate(coordinate)
    }
}
